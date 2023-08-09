#include<bits/stdc++.h>
using namespace std;

struct rod{
    int length;
    int price;
    int maxProfit;
}cutLength[1000];
int numberOfInput, totalLength;

void readInput(){
    cin>>numberOfInput>>totalLength;
    for(int i=0; i<numberOfInput; i++){
        cin>>cutLength[i].length>>cutLength[i].price;
        cutLength[i].maxProfit = -100;
    }
}

void printResult(){
    for(int i=0; i<numberOfInput; i++){
        cout<<cutLength[i].length<<" "<<cutLength[i].price<<" "<<cutLength[i].maxProfit<<endl;
    }
    cout<<"------------------------------------------------------------------"<<endl;
}

int calcMaxProfit(int i){
    if(cutLength[i].maxProfit >= 0){
        return cutLength[i].maxProfit;
    } 
    else if( i==0 ){
        return 0;
    }
    else{
        int profit = -1;
        for(int j=1; j<=i; j++){
            profit = max(profit, cutLength[j].price + calcMaxProfit(i-j));
            //cout<<"calc "<< cutLength[j].price<<" "<<calcMaxProfit(i-j)<<endl;
        }
        return profit;
    } 
}

void cutRod(){
    for(int i=0; i<=totalLength; i++){
        cutLength[i].maxProfit = calcMaxProfit(i);
    }
}

int main(){
    
    freopen("rodCutting_input.txt", "r", stdin);
    readInput();
    printResult();
    cutRod();
    printResult();
    cout<<cutLength[1].price;
}