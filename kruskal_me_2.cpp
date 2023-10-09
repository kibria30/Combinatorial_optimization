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
int numOfSelectedEdge=0;

bool compareEdges(const pair<int, Edge>& a, const pair<int, Edge>& b) {
    return a.first < b.first;
}

vertex* findUltimateParent(vertex* x){
    if(x->name == x->ultimateParent->name)
        return x;
    else{
        return findUltimateParent(x->ultimateParent);
    }
}

void link_set(vertex* u, vertex* v){
    if(u->rank > v->rank){
        v->ultimateParent = u;
    }
    else{
        u->ultimateParent = v;
        if(u->rank == v->rank){
            v->rank++;
        }
    }
}

void union_set(vertex* u, vertex* v){
    link_set(findUltimateParent(u), findUltimateParent(u));
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
    
    Edge* edge;
    for(int i=0; i<edges.size(); i++){
        edge = &edges[i].second;
        //cout<<edges[i].second.u.name<<" "<<edges[i].second.v.name<<endl;
        if(findUltimateParent(edge->u)->name != findUltimateParent(edge->v)->name){
            mst.push_back(edge);
            union_set(edge->u, edge->v);
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
        edges.push_back(make_pair(edge.w, edge));
    }

    MST();

    cout<<"selected edges are: "<<endl;
    for(auto i:mst){
        cout<<i.u.name<<" - "<<i.v.name<<endl;
    }
}