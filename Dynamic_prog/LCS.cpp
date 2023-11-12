#include<bits/stdc++.h>
#define diarrow -100
#define uparrow -101
#define lftarrow -102
#define MAX 1000
using namespace std;

struct cell{
    int count;
    int arrow;
}Matrix[MAX][MAX];

char str1[100], str2[100];

void LCS(int m, int n){
    for(int i=0; i<=m; i++) Matrix[i][0].count = 0;
    for(int j=1; j<=n; j++) Matrix[0][j].count = 0;

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(str1[i-1]==str2[j-1]){   // vul hoy karon string suru hoice 0 index theke but matrix e count korsi 1 theke
                Matrix[i][j].count = Matrix[i-1][j-1].count + 1;
                Matrix[i][j].arrow = diarrow;
            }
            else if(Matrix[i-1][j].count >= Matrix[i][j-1].count){
                Matrix[i][j].count = Matrix[i-1][j].count;
                Matrix[i][j].arrow = uparrow;
            }
            else{
                Matrix[i][j].count = Matrix[i][j-1].count;
                Matrix[i][j].arrow = lftarrow;
            }
        }
    }
}

void printLCS(int m, int n){
    if(m==0 || n==0){
        return;
    }
    else if(Matrix[m][n].arrow == diarrow){
        printLCS(m-1, n-1);
        cout<<str1[m-1];   //vul korsilam string er indexing suru hoy 0 theke
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

    LCS(m, n);
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            cout<<Matrix[i][j].count<< " ";
        }
        cout<<endl;
    }
    printLCS(m, n);     // sequence is a very important fact
    cout<<endl;         // Matrix bananor somoy o sequence break kore na
    cout<<Matrix[m][n].count<<endl;
}

/* 
ABCBDAB
ABCABAGHD
Ans: 5
seq: ABCBD
*/