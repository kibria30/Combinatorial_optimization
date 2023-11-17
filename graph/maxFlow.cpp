#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int V = 6;
int parent[V];
int graph[V][V], d[V], prv[V], n = 0;
string name[V];
bool isPushed[V];
priority_queue< pair<int, int>, vector< pair<int, int>>, greater < pair<int, int>>> stock;  //greater<> reverse the order

void readInput(){
    int u, v;
    string s;
    while (cin>>s){
        if(s == "END")
            break;

        for(u = 0; u < n; u++){
            if(name[u] == s)
                break;
        }
        if (u == n){
            name[n] = s;
            n++;
        }

        cin >> s;
        for(v = 0; v < n; v++){
            if(name[v] == s)
                break;
        }
        if (v == n){
            name[n] = s;
            n++;
        }

        cin >> graph[u][v];
        //graph[v][u] = graph[u][v];            //eita korle ans 23 theke 24 hocce but why

    }
}

void printGraph(){
    cout<<"Adj-Matrix is: "<<endl;
    int u, v;
    for (u = 0; u < n; u++ ){
        for(v = 0; v < n; v++){
            cout << graph[u][v] << " ";
        }
        cout << "\n";
    }
}

bool bfs(int source, int sink) {
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;
    parent[source] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return visited[sink];
}

int fordFulkerson(int source, int sink) {
    int maxFlow = 0;

    while (bfs(source, sink)) {
        int pathFlow = INF;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, graph[u][v]);
        }

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            graph[u][v] -= pathFlow;
            graph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() {

    freopen("maxflow_input.txt", "r", stdin);
    readInput();
    printGraph();

    int source = 0;
    int sink = 5;

    int maxFlow = fordFulkerson(source, sink);

    cout << "Maximum Flow: " << maxFlow << endl;

    return 0;
}