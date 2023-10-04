#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct vertex{
    string name;
    int rank;
};

struct vertexWithParent{
    vertex itself;
    vertex ultimateParent;
};

struct Edge{
    vertexWithParent u, v;
    int w;
};

priority_queue< pair<int, Edge>, vector< pair<int, Edge>>, greater < pair<int, Edge>>> edges;
vector<Edge> mst;
int numOfEdges;
int numOfSelectedEdge;

string findUltimateParent(vertexWithParent x){
    if(x.itself.name == x.ultimateParent.name)
        return x.itself.name;
    else{
        x.ultimateParent = findUltimateParent(x.ultimateParent);
    }
    
}

void MST(){
    
    for(int i=0; i<edges.size(); i++){
        Edge edge = edges.top().second;
        edges.pop();
        if(findUltimateParent(edge.u) == findUltimateParent(edge.v));
    }
}

int main(){
    freopen("kuskal_input.txt", "r", stdin);
    cin>>numOfEdges;
    Edge edge;
    for(int i=0; i<numOfEdges; i++){
        cin>>edge.u.itself.name>>edge.v.itself.name>>edge.w;
        edge.u.itself.rank = 0;
        edge.u.ultimateParent = edge.u.itself;
        edge.v.itself.rank = 0;
        edge.v.ultimateParent = edge.v.itself;
        edges.push(make_pair(edge.w, edge));
    }

    MST();
}