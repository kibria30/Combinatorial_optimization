#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct Edge{
    char u, v;
    int w;
};

vector<Edge> edges;
vector<Edge> mst;
vector<int> rank;
vector<int> uParent;

int numOfVertex;
int numOfEdge;
int numOfSelectedEdge=0;

bool compareEdges(const Edge& a, const Edge& b) {
    return a.w < b.w;
}

vertex findUltimateParent(vertex& x){
    if(x.name == x.ultimateParent->name){
        cout<<x.name<<"-x.name"<<endl;
        return x;
    }
        
    else{
        return findUltimateParent(*x.ultimateParent);
    }
}

void link_set(vertex& u, vertex& v){
    //cout<<"hello link"<<endl;
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
    //cout<<"hello union"<<endl;
    vertex parentU = findUltimateParent(u);
    vertex parentV = findUltimateParent(v);
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

    for(int i=0; i<edges.size(); i++){
        cout<<edges[i].u.name<<" parent "<<edges[i].u.ultimateParent->name<<" "<<edges[i].v.name<<" "<<" parent "<<edges[i].v.ultimateParent->name<<" "<<edges[i].w<<endl;
    }

    cout<<endl<<"gap"<<endl;

    sort(edges.begin(), edges.end(), compareEdges);
    
    for(int i=0; i<edges.size(); i++){
        cout<<edges[i].u.name<<" parent "<<edges[i].u.ultimateParent->name<<" "<<edges[i].v.name<<" "<<edges[i].w<<endl;
    }

    for(int i=0; i<edges.size(); i++){
        cout<<edges[i].u.name<<" "<<edges[i].v.name<<endl;
        cout<<"hello MSSSST"<<endl;
        if(findUltimateParent(edges[i].u).name != findUltimateParent(edges[i].v).name){
                    cout<<"hello MSSSST-2"<<endl;
            mst.push_back(edges[i]);
            union_set(edges[i].u, edges[i].v);
            numOfSelectedEdge++;
        }
        //if(numOfSelectedEdge == numOfVertex-1) return;
    }
}

int main(){
    freopen("kruskal_Input.txt", "r", stdin);
    cin >> numOfVertex >> numOfEdge;
    Edge edge;
    for(int i=0; i<numOfEdges; i++){
        cin>>edge.u>>edge.v>>edge.w;
        edges.push_back(edge);
    }

    MST();

    cout<<"hello";

    cout<<"selected edges are: "<<endl;
    for(auto i:mst){
        cout<<i.u.name<<" - "<<i.v.name<<endl;
    }
}