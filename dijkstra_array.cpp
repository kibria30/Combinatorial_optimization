#include<iostream>
#include<queue>

using namespace std;

#define SIZE 100
#define INFINITY 1000000


int w[SIZE][SIZE], d[SIZE], parent[SIZE];
int n = 0;
bool flag[SIZE];
string name[SIZE];

void readInput()
{
    int u, v;
    string s;
    while (cin>>s)
    {
        if(s == "END")
            break;

        for(u = 0; u < n; u++)
        {
            if(name[u] == s)
                break;
        }
        if (u == n)
        {
            name[n] = s;
            n++;
        }

        cin >> s;
        for(v = 0; v < n; v++)
        {
            if(name[v] == s)
                break;
        }
        if (v == n)
        {
            name[n] = s;
            n++;
        }

        cin >> w[u][v];

    }
}

void printGraph()
{
    int u, v;
    for (u = 0; u < n; u++ )
    {
        for(v = 0; v < n; v++)
        {
            cout << w[u][v] << " ";
        }
        cout << "\n";
    }
}

void initialize_single_source(int s)
{
    for (int v = 0; v < n; v++)
    {
        d[v] = INFINITY;
        parent[v] = -1;
    }
    d[s] = 0;
}

int extract_min(){
    int m = INFINITY, index=-1;

    for(int i=0; i<n; i++){
        if(flag[i] && m > d[i]){
            m = d[i];
            index = i;
        }
    }
    return index;
}

void relax(int u, int v)
{
    if(d[v] > d[u] + w[u][v])
    {
        d[v] = d[u] + w[u][v];
        parent[v] = u;
    }
}

void dijkstra(int s)
{
    
    initialize_single_source(s);

    for(int i=0; i<n; i++){ //Q <- V[G]
        flag[i] = true;
    }
    int queueSize = n;
    while(queueSize)
    {
        int u = extract_min();
        for (int v = 0; v < n; v++)
        {
            if(w[u][v] > 0)
            {
                relax(u, v);
            }
        }
        queueSize--;
    }
}

void printPath(int destination){
    if(destination = 0){
        cout<< name[destination]<<" ";
        return;
    }
    cout<<name[destination]<<" ";
}


int main(){
    freopen("graph_input.txt", "r", stdin);
    readInput();
    printGraph();
    dijkstra(0);
    //printPath(2);
    for(int i=0; i<n;  i++){
        cout<<name[i] <<" "<<d[i]<<" "<<parent[i]<<endl; 
    }
    cout<<endl;
}