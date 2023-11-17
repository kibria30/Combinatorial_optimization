#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <tuple>

using namespace std;

vector<tuple<string,string,int>> prim(vector<tuple<string,string,int>> edges,unordered_map<string, vector<pair<string, int>>> adjacencyList) 
{
    priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>> pq;
    unordered_map<string,bool> visited;
    vector<tuple<string,string,int>> primEdges;

    string startVertex=get<0>(edges[0]); 
    visited[startVertex]=true;

    for(auto neighbor: adjacencyList.at(startVertex)) 
    {
        pq.push({neighbor.second,neighbor.first});
    }

    while(!pq.empty()) 
    {
        auto currentEdge=pq.top();
        pq.pop();
        string currentVertex=currentEdge.second;
        int weight=currentEdge.first;
        if(visited[currentVertex]) 
        {
            continue;
        }
        visited[currentVertex]=true;
        primEdges.push_back(make_tuple(startVertex,currentVertex,weight));

        for(const auto& neighbor: adjacencyList.at(currentVertex)) 
        {
            if(!visited[neighbor.first]) 
            {
                pq.push({neighbor.second,neighbor.first});
            }
        }
        startVertex=currentVertex;
    }

    return primEdges;
}

string findParent(unordered_map<string, string> &parent,string vertex)
{
    if(parent[vertex]=="")
        return vertex;
    return findParent(parent,parent[vertex]);
}
void unionSets(unordered_map<string, string> &parent,string x,string y)
{
    string rootX=findParent(parent,x);
    string rootY=findParent(parent,y);
    parent[rootX]=rootY;
}

vector<tuple<string,string,int>> kruskal(vector<tuple<string,string,int>> edges)
{
    sort(edges.begin(),edges.end(),[](const auto& a,const auto& b)
    {
        return get<2>(a)<get<2>(b);
    });

    unordered_map<string, string> parent;
    vector<tuple<string,string,int>> kruskalEdges;
    for(auto edge: edges)
    {
        string sourceRoot=findParent(parent,get<0>(edge));
        string destRoot=findParent(parent,get<1>(edge));
        if(sourceRoot!=destRoot)
        {
            kruskalEdges.push_back(edge);
            unionSets(parent,sourceRoot,destRoot);
        }
    }
    return kruskalEdges;
}

void input(vector<tuple<string,string,int>> &edges,unordered_map<string, vector<pair<string, int>>> &adjacencyList)
{
    if(freopen("lab_final_input.txt", "r", stdin)==NULL)
    {
        cout<<"Cannot open file\n";
        return;
    }
    int numberOfVertices,numberOfEdges;
    cin>>numberOfVertices>>numberOfEdges;
    for (int i=0;i<numberOfEdges;++i)
    {
        string source,destination;
        int weight;
        cin>>source>>destination>>weight;
        edges.push_back(make_tuple(source,destination,weight));
        adjacencyList[source].emplace_back(destination, weight);
        adjacencyList[destination].emplace_back(source, weight);
    }
}

int printGraph(vector<tuple<string,string,int>>edges)
{
    int totalWeight=0;
    cout<<"Spanning tree is:\n";
    for(auto edge: edges)
    {
        cout<<"From  : "<<get<0>(edge)<<"  to  : "<<get<1>(edge)<<"  with weight  : "<<get<2>(edge)<<endl;
        totalWeight+=get<2>(edge);
    }
    cout<<"Total cost is  : "<<totalWeight<<endl;
    return totalWeight;
}

int main()
{
    vector<tuple<string,string,int>> edges;
    unordered_map<string, vector<pair<string, int>>> adjacencyList;

    input(edges,adjacencyList);
    //printGraph(edges);

    vector<tuple<string,string,int>> kruskalEdges=kruskal(edges);
    //printGraph(kruskalEdges);

    vector<tuple<string,string,int>> primEdges=prim(edges,adjacencyList);
    //printGraph(primEdges);

    cout<<"Maximum saved is: "<<printGraph(edges)-printGraph(kruskalEdges)<<endl;
    return 0;
}