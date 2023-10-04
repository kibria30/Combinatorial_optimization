#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct vertex{
    string name;
    int rank;
    struct vertex *ultimateParent;
};

struct Edge{
    vertex u, v;
    int w;
};

vector< pair<int, Edge>> edges;
vector<Edge> mst;
int numOfEdges;
int numOfSelectedEdge;

bool compareEdges(const pair<int, Edge>& a, const pair<int, Edge>& b) {
    return a.first < b.first;
}

string findUltimateParent(vertex x){
    if(x.name == x.ultimateParent->name)
        return x.name;
    else{
        x.ultimateParent = findUltimateParent(x.ultimateParent);
        return x.ultimateParent->name;
    }
}

void union(vertex &u, vertex &v){
    if(u.rank > v.rank){
        v.ultimateParent = &u;
    }
}

void make_set(){
    for(int i = 0; i<edges.size(); i++){
        edges[i].second.u.rank = 0;
        edges[i].second.u.ultimateParent = &edges[i].second.u;
        edges[i].second.v.rank = 0;
        edges[i].second.v.ultimateParent = &edges[i].second.v;
    }
}

void MST(){

    make_set();

    sort(edges.begin(), edges.end(), compareEdges);
    
    Edge edge;
    for(int i=0; i<edges.size(); i++){
        edge = edges[i].second;
        //cout<<edges[i].second.u.name<<" "<<edges[i].second.v.name<<endl;
        if(findUltimateParent(edge.u) != findUltimateParent(edge.v)){
            mst.push_back(edge);
            union(edge.u, edge.v);
        }
    }
}

int main(){
    freopen("kruskal_Input.txt", "r", stdin);
    cin>>numOfEdges;
    Edge edge;
    for(int i=0; i<numOfEdges; i++){
        cin>>edge.u.name>>edge.v.name>>edge.w;
        edges.push_back(make_pair(edge.w, edge));
    }

    MST();
}