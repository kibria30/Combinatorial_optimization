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

vector<Edge> edges;
vector<Edge> mst;
int numOfEdges;
int numOfSelectedEdge=0;

bool compareEdges(const Edge& a, const Edge& b) {
    return a.w < b.w;
}

vertex findUltimateParent(vertex& x){
    if(x.name == x.ultimateParent->name)
        return x;
    else{
        return findUltimateParent(*x.ultimateParent);
    }
}

void link_set(vertex& u, vertex& v){
    if(u.rank > v.rank){
        v.ultimateParent = &u;
    }
    else{
        u.ultimateParent = &v;
        if(u.rank == v.rank){
            v.rank++;
        }
    }
}

void union_set(vertex& u, vertex& v){
    link_set(findUltimateParent(u), findUltimateParent(v));
}

void make_set(){
    for(int i = 0; i<edges.size(); i++){
        edges[i].u.rank = 0;
        edges[i].u.ultimateParent = &edges[i].u;
        edges[i].v.rank = 0;
        edges[i].v.ultimateParent = &edges[i].v;
    }
}

void MST(){

    make_set();

    sort(edges.begin(), edges.end(), compareEdges);
    
    for(int i=0; i<edges.size(); i++){
        //cout<<edges[i].second.u.name<<" "<<edges[i].second.v.name<<endl;
        if(findUltimateParent(edges[i].u).name != findUltimateParent(edges[i].v).name){
            mst.push_back(edges[i]);
            union_set(edges[i].u, edges[i].v);
            numOfSelectedEdge++;
        }
        //if(numOfSelectedEdge == numOfVertex-1) return;
    }
}

int main(){
    freopen("kruskal_Input.txt", "r", stdin);
    cin>>numOfEdges;
    Edge edge;
    for(int i=0; i<numOfEdges; i++){
        cin>>edge.u.name>>edge.v.name>>edge.w;
        edges.push_back(edge);
    }

    MST();

    cout<<"selected edges are: "<<endl;
    for(auto i:mst){
        cout<<i.u.name<<" - "<<i.v.name<<endl;
    }
}