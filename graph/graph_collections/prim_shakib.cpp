#include <bits/stdc++.h>
#define V 100

using namespace std;
int graph[V][V];

string name[100];
int n = 0, m;

void readInput(){
    int u, v, w;
    string s;

    cin >> m;
    while (cin >> s){
        if (s == "END")
            break;

        for (u = 0; u < n; u++){
            if (name[u] == s)
                break;
        }
        if (u == n){
            name[n] = s;
            n++;
        }

        cin >> s;
        for (v = 0; v < n; v++){
            if (name[v] == s)
                break;
        }
        if (v == n){
            name[n] = s;
            n++;
        }
        cin >> w;

        graph[u][v] = w;
    }
}

int minimumvertex(vector<int> &value, vector<bool> &setMst){
    int minimum = INT_MAX;
    int vertex;

    for (int i = 0; i < n; i++){
        if (setMst[i] == false && value[i] < minimum){
            vertex = i;
            minimum = value[i];
        }
    }
    return vertex;
}

void findMst(){
    int parent[V];
    vector<int> value(V, INT_MAX);
    vector<bool> setMst(V, false);

    parent[0] = -1;
    value[0] = 0;

    for (int i = 0; i < n - 1; i++){
        int u = minimumvertex(value, setMst);
        setMst[u] = true;

        for (int j = 0; j < V; j++){
            if (graph[u][j] != 0 && setMst[j] == false && graph[u][j] < value[j]){
                value[j] = graph[u][j];
                parent[j] = u;
            }
        }
    }
    int sum = 0;
    cout<<"Select edges: "<<endl;
    for (int i = 1; i < n; i++){
        cout<< name[parent[i]] << " - " << name[i] << " : " << graph[parent[i]][i] << endl;
        sum += graph[parent[i]][i];
    }
    cout <<endl<< "total distance:" << sum<<endl;
}

int main(){
    freopen("kruskal_Input.txt", "r", stdin);
    readInput();

    findMst();
}