#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

string name[100];
int n=0,m;
vector<Edge> edges;

void readInput(){
    int u, v,w;
    string s;

    cin>>m;
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
        cin>>w;
        edges.push_back({u,v,w});
    }
}

bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

int findParent(int vertex, vector<int>& parent) {
    if (parent[vertex] == -1)
        return vertex;
    return findParent(parent[vertex], parent);
}

void kruskal() {
    sort(edges.begin(), edges.end(), compareEdges);

    vector<int> parent(n, -1);
    vector<Edge> mst;

    for (Edge edge : edges) {
        int u =edge.src;
        int v =edge.dest;

        int uParent = findParent(u, parent);
        int vParent = findParent(v, parent);

        if (uParent != vParent) {
            mst.push_back(edge);
            parent[uParent] = vParent;
        }
    }

    cout << "Minimum Spanning Tree:" << endl;
    int sum=0;
    for (Edge edge : mst) {
        cout << name[edge.src] << " - " << name[edge.dest]<< " : " << edge.weight << endl;
        sum+=edge.weight;
    }
    cout<<"total path:"<<sum;
}

int main() {
    freopen("kruskal_Input.txt","r",stdin);
    readInput();
    kruskal();
}