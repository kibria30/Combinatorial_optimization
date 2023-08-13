#include<bits/stdc++.h>
#define leftarrow -100
#define uparrow -101
#define diagarrow -102
#define empdiarrow -103
#define MAX 1000
using namespace std;

struct cell{
    int count;
    int operation;
}matrix[MAX][MAX];

char str1[100], str2[100];

void editDistance(int m, int n){
    matrix[0][0].count = 0;
    for(int i=1; i<=m ; i++){
        matrix[i][0].count = i;
        matrix[i][0].operation = uparrow;
    }

    for(int j=1; j<=n; j++){
        matrix[0][j].count = j;
        matrix[0][j].operation = leftarrow;
    }

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(str1[i-1] == str2[j-1]){     // matrix from 1,1 but string from 0 index
                matrix[i][j].count = matrix[i-1][j-1].count;
                matrix[i][j].operation = empdiarrow;
            }
            else if(matrix[i-1][j-1].count <= matrix[i-1][j].count && matrix[i-1][j-1].count <= matrix[i][j-1].count){
                matrix[i][j].count = matrix[i-1][j-1].count + 1;
                matrix[i][j].operation = diagarrow;
            }
            else if(matrix[i-1][j].count <= matrix[i-1][j-1].count && matrix[i-1][j].count <= matrix[i][j-1].count){
                matrix[i][j].count = matrix[i-1][j].count + 1;
                matrix[i][j].operation = uparrow;
            }
            else{
                matrix[i][j].count = matrix[i][j-1].count + 1;
                matrix[i][j].operation = leftarrow;
            }
        }
    }
}

void printOperations(int m, int n){
    if(m==0 && n==0) return;
    if(matrix[m][n].operation == uparrow){
        printOperations(m-1, n);
        cout<<"Delete: "<<str1[m-1]<<endl;     // matrix from 1,1 but string from 0 index
    }
    else if(matrix[m][n].operation == leftarrow){
        printOperations(m, n-1);
        cout<<"Insert: "<<str2[n-1]<<endl;      // matrix from 1,1 but string from 0 index
    }
    else if(matrix[m][n].operation == diagarrow){
        printOperations(m-1, n-1);
        cout<<"Replace: "<<str1[m-1]<<" by "<<str2[n-1]<<endl;   // matrix from 1,1 but string from 0 index
    }
    else{
        printOperations(m-1, n-1);
        cout<<"No operation needed."<<endl;
    }
}

int main(){

    freopen("ED_input.txt", "r", stdin);
    cin>>str1>>str2;
    int m = strlen(str1);
    int n = strlen(str2);

    editDistance(m, n);
    cout<<"Total operations needed: "<<matrix[m][n].count<<endl;
    printOperations(m, n);

}