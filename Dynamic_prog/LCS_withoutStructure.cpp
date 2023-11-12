#include<bits/stdc++.h>
#define MAX 1000
#define INF 1e9
using namespace std;

//not finished 
//almost finished but wrong answer

int Matrix[MAX][MAX];
char str1[100], str2[100];

void initiateMatrix(int m, int n){
    for(int i = 0; i<= m; i++){
        for(int j=0; j<=n ; j++){
            Matrix[i][j]= -1;
        }
    }
}

int LCS(int m, int n){

    if(m==0 || n==0){
        Matrix[m][n] == 0;
        return 0;
    } 
    else if(Matrix[m][n] >= 0 ){
        return Matrix[m][n];
    }
    else if(str1[m-1] == str2[n-1]){
        Matrix[m][n] = LCS(m-1, n-1) + 1;
        return Matrix[m][n];
    }
    else{
        if(LCS(m-1, n) > LCS(m, n-1)){
            Matrix[m][n]= LCS(m-1, n);
            return Matrix[m][n];
        }
        else{
            Matrix[m][n] = LCS(m, n-1);
            return Matrix[m][n];
        }
    }

}

void printLCS(int m, int n){
    if(m==0 || n==0){
        return;
    }
    else if( str1[m] == str2[n]){
        printLCS(m-1, n-1);
        cout<<str1[m-1]<<"->";   
    }
    else{
        if(Matrix[m-1][n] > Matrix[m][n-1]){
            printLCS(m-1, n);
        }
        else
            printLCS(m, n-1);

    } 

}

int main(){

    freopen("LCS_input.txt", "r", stdin);
    cin>>str1>>str2;
   
    int m = strlen(str1);
    int n = strlen(str2);

    initiateMatrix(m,n);
    
    cout<<LCS(m, n)<<endl;

    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            cout<<Matrix[i][j]<< " ";
        }
        cout<<endl;
    }
    printLCS(m, n);
    cout<<endl;
}

/* 
ABCBDAB
ABCABAGHD
Ans: 5
seq: ABCAB  // it can be varied for iterative and memoized version 
*/