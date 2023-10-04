#include<iostream>
#include<queue>
#include<functional>
#include<vector>

using namespace std;

#define SIZE 100
#define INFINITY 1000000

int w[SIZE][SIZE], prv[SIZE];
int n = 0;
string name[SIZE];

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

        cin >> w[u][v];

    }
}

void printGraph(){   
    cout<<"Adj-Matrix is: "<<endl;
    int u, v;
    for (u = 0; u < n; u++ ){
        for(v = 0; v < n; v++){
            cout << w[u][v] << " ";
        }
        cout << "\n";
    }
}

bool bfs(int s, int t){

    bool visited[SIZE];
    memset(visited, 0, sizeof(visited));
    int parent[SIZE];
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
 
    while (!q.empty()) {
        int u = q.front();
        q.pop();
 
        for (int v = 1; v <= n; v++) {
            if (visited[v] == false && w[u][v] > 0) {
                if (v == t) {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return false;
}

int main(){

    freopen("maxFlow_input.txt","r",stdin);
    readInput();
    printGraph();

}