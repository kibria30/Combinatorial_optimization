#include<bits/stdc++.h>
#define diarrow -100
#define uparrow -101
#define lftarrow -102
#define MAX 1000
#define INF 1e9
using namespace std;

struct cell{
    int count;
    int arrow;
}Matrix[MAX][MAX];

char str1[100], str2[100];

void initiateatrix(int m, int n){
    for(int i = 0; i<= m; i++){
        for(int j=0; j<=n ; j++){
            Matrix[i][j].count = -INF;
        }
    }
}

int LCS(int m, int n){

    if(m==0 || n==0){
        Matrix[m][n].count == 0;
        return 0;
    } 
    else if(Matrix[m][n].count >=0 ){
        return Matrix[m][n].count;
    }
    else if(str1[m-1] == str2[n-1]){
        Matrix[m][n].count = LCS(m-1, n-1) + 1;
        Matrix[m][n].arrow = diarrow;
        return Matrix[m][n].count;
    }
    else{
        if(LCS(m-1, n) > LCS(m, n-1)){
            Matrix[m][n].count = LCS(m-1, n);
            Matrix[m][n].arrow = uparrow;
            return Matrix[m][n].count;
        }
        else{
            Matrix[m][n].count = LCS(m, n-1);
            Matrix[m][n].arrow = lftarrow;
            return Matrix[m][n].count;
        }
    }

}

void printLCS(int m, int n){
    if(m==0 || n==0){
        return;
    }
    else if(Matrix[m][n].arrow == diarrow){
        printLCS(m-1, n-1);
        cout<<str1[m-1]<<"->";   
    }
    else if(Matrix[m][n].arrow == uparrow){
        printLCS(m-1, n);
    }
    else if(Matrix[m][n].arrow == lftarrow){
        printLCS(m, n-1);
    }
}

int main(){

    freopen("LCS_input.txt", "r", stdin);
    cin>>str1>>str2;
   
    int m = strlen(str1);
    int n = strlen(str2);

    initiateatrix(m,n);
    
    cout<<LCS(m, n)<<endl;

    // for(int i=0; i<=m; i++){
    //     for(int j=0; j<=n; j++){
    //         cout<<Matrix[i][j].count<< " ";
    //     }
    //     cout<<endl;
    // }
    printLCS(m, n);
    cout<<endl;
}

/* 
ABCBDAB
ABCABAGHD
Ans: 5
seq: ABCAB  // it can be varied for iterative and memoized version 
*/