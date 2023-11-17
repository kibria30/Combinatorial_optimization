#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 10e6
using namespace std;

struct vertex{
    string name;
    int rank;
    struct vertex *ultimateParent;
};

struct Edge{
    vertex u, v;
    int w;
    bool isProcessed;
};

vector<Edge> edges;
vector<Edge> mst;
int numOfVertex, numOfEdges;
int numOfSelectedEdge=0;

int minWeightEdge(){
    int minIndex;
    int weight = INF;
    for(int i=0; i<edges.size(); i++){
        if(!edges[i].isProcessed && edges[i].w < weight){
            weight = edges[i].w;
            minIndex = i;
        }
    }
    edges[minIndex].isProcessed = true;
    return minIndex;
}

vertex* findUltimateParent(vertex *x){
    if(x->name == x->ultimateParent->name){
        return x;
    }
    else{
        return findUltimateParent(x->ultimateParent);
    }
}

void link_set(vertex *u, vertex *v){
    if(u->rank > v->rank){
        v->ultimateParent = u;
    }
    else{
        u->ultimateParent =  v;
        if(u->rank == v->rank){
            v->rank++; 
        }
    }
}

void union_set(vertex *u, vertex *v){
    cout<<"from union {vertex} = "<< u->name<<" "<<v->name<<endl;
    vertex *parentU = findUltimateParent(u);
    vertex *parentV = findUltimateParent(v);
    cout<<"from union {parent} = "<< parentU->name<<" "<<parentV->name<<endl;
    link_set(parentU, parentV);
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

    int minIndex;
    while(numOfSelectedEdge < numOfVertex-1){
        minIndex = minWeightEdge();
        cout<<"vertex = "<<edges[minIndex].u.name<<" "<<edges[minIndex].v.name<<endl;
        cout<<"parent = "<< findUltimateParent(&edges[minIndex].u)->name<<" "
            <<findUltimateParent(&edges[minIndex].v)->name<<endl;
        if(findUltimateParent(&edges[minIndex].u)->name != findUltimateParent(&edges[minIndex].v)->name){
            mst.push_back(edges[minIndex]);
            union_set(&edges[minIndex].u, &edges[minIndex].v);
            numOfSelectedEdge++;
        }
        // if(findUltimateParent(&edges[minIndex].u)->name == findUltimateParent(&edges[minIndex].v)->name){
        //     cout<<"=="<<edges[minIndex].u.name<<" "<<edges[minIndex].v.name<<" "<<edges[minIndex].w<<endl;
        // }
    }
}

int main(){
    freopen("kruskal_Input.txt", "r", stdin);
    cin>>numOfVertex>>numOfEdges;
    Edge edge;
    for(int i=0; i<numOfEdges; i++){
        cin>>edge.u.name>>edge.v.name>>edge.w;
        edge.isProcessed = false;
        edges.push_back(edge);
    }

    MST();

    cout<<"selected edges are: "<<endl;
    int mstWeight = 0;
    for(auto i:mst){
        cout<<i.u.name<<" - "<<i.v.name<<endl;
        mstWeight += i.w;
    }
    cout<<"Sum of spanning tree: "<<mstWeight<<endl;
}