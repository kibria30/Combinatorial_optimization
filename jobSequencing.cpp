#include<bits/stdc++.h>
using namespace std;

struct node{
    char id;
    int start;
    int end;
};

struct node job[1000];
pair<int, struct node> jobs;
vector<pair <int, struct node> > pairs;
vector<struct node> solution;
int n;

void sequece(){
    
}

int main(){
    
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>job[i].id;
        cin>>job[i].start;
        cin>>job[i].end;
        jobs.first = job[i].end;
        jobs.second = job[i];
        pairs.push_back(jobs);
    } 

    sort(pairs.begin(), pairs.end());

    solution.push_back(pairs[0].second);
    
    void squence();

}