#include<bits/stdc++.h>
#define insert -100
#define delete -101
#define substitute -102
#define none -103
#define MAX 1000
using namespace std;

struct cell{
    int count;
    int operation;
}matrix[MAX][MAX];

char str1[100], str2[100];

void editDistance(int m, int n){
    matrix[0][0] = 0;
    for(int i=1; i<=m ; i++){
        matrix[i][0].count = i;
        matrix[i][0].operation = delete;
    }

    for(int j=1; j<=n; j++){
        matrix[0][j].count = j;
        matrix[0][j].operation = insert;
    }

    
}

int main(){

    cin>>str1>>str2;
    int m = strlen(str1);
    int n = strlen(str2)

    

}