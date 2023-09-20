#include<iostream>
#include<queue>
#include<functional>
#include<vector>

using namespace std;

#define SIZE 100
#define INFINITY 1000000

// struct comparePair(pair<int, int> &leftEle, pair<int, int> &rightEle){
//     return leftEle.first < rightEle.first;        
// }                                                   // why does not work

int w[SIZE][SIZE], d[SIZE], prv[SIZE];
int n = 0;
string name[SIZE];
priority_queue< pair<int, int>, vector< pair<int, int>>, greater < pair<int, int>>> stock;  //greater reverse the order

void readInput(){
    int u, v;
    string s;
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

        cin >> w[u][v];

    }
}

void printGraph(){   
    cout<<"Adj-Matrix is: "<<endl;
    int u, v;
    for (u = 0; u < n; u++ ){
        for(v = 0; v < n; v++){
            cout << w[u][v] << " ";
        }
        cout << "\n";
    }
}

void initiate(int source){

    for(int i=0; i<n; i++){
        d[i] = INFINITY;
        prv[i] = -1;
    }
    d[source] = 0;
}

void relax(int u, int v){
    if(d[v] > d[u] + w[u][v]){
        d[v] = d[u] + w[u][v];
        cout<<"relax "<<name[v]<<d[v]<<endl;
        prv[v] = u;
    }
}

void dijkstra(int source){
    initiate(source);

    for(int i=0; i<n; i++){
        stock.push(make_pair(d[i], i));   // pair e first element distance and second element index rakhsi
    }

    while(!stock.empty()){
        pair<int ,int> curr = stock.top();    // fail to pick up minumum element

        cout<<name[curr.second]<<" "<<endl;
        for(int i=0; i<n; i++){
            if(w[curr.second][i])
                relax(curr.second, i);
        }
        cout<<"poping "<<name[curr.second]<<" "<<curr.first<<endl;
        stock.pop();  // why c poped before d
        cout<<"top after poping : "<<name[stock.top().second]<<stock.top().first<<endl;
        cout<<"d[u] after dijkstra :"<<endl;
        for(int i=0; i<n; i++){
            cout<<name[i]<<"-"<<d[i]<<" ";
        }
        cout<<endl;
    }
}

void traverse(int source, int v){
    if(v == source) {
        cout<<name[source]<<" -> ";
        return;
    }
    traverse(source, prv[v]);
    cout<<name[v]<<" -> ";
}

void printPath(int source){
    for(int i=0; i<n; i++){
        if(i != source){
            cout<<"Shortest path from "<<name[source]<<" to "<<name[i]<<" : ";
            traverse(source, i);
            cout<<endl;
        }
            
    }
}

int main(){

    freopen("dijk_input_2.txt","r",stdin);
    readInput();
    printGraph();

    int source = 0;
    dijkstra(source);

    cout<<"d[u] after dijkstra :"<<endl;
    for(int i=0; i<n; i++){
        cout<<name[i]<<"-"<<d[i]<<" ";
    }
    cout<<endl;
    cout<<"parents for every node: "<<endl;
    for(int i=0; i<n; i++){
        cout<<name[i]<<"-"<<name[prv[i]]<<" ";
    }
    cout<<endl;
    printPath(source);

}