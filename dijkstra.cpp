#include<iostream>
#include<queue>
#include<vector>
#define INF 1e9
#define MAX 1000

using namespace std;

struct Node{
    string name;
    int distance;
    bool isVisited;
    string parent;
};

vector<string> vertex;
vector< pair< Node, Node>> graph[MAX]; 
int numOfvertex;

void getInput(){
    cin >> numOfvertex;
    
}

void intiate(){
    Node input;
    cin >> numOfvertex;
    for(int i=0; i<numOfvertex; i++){
        cin>>input.name;
        input.distance = INF;
        input.isVisited = false;
        input.parent = NULL;
        vertex.push_back(input);
    }
    resize(vertex);
    string from, to;
    for(int i=0; i<numOfvertex; i++){
        
    }
}

int main(){

}