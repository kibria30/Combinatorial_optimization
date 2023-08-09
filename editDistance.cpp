#include <bits/stdc++.h>
using namespace std;

char up = 'u';
char leftr = 'l';
char diagonal = 'd';
char none = 'n';

char a[] = "aloo";
char b[] = "potol";

struct node{
    char arrow;
    int operation;
}matrix[1000][1000];

int findMin(int x, int y, int z){
    if (x <= y && x <= z)
        return x;
    else if (y <= x && y <= z)
        return y;
    else
        return z;
}

int findDistance(char a[], char b[]){
    int len_a = strlen(a);
    int len_b = strlen(b);

    for (int i = 0; i <= len_a; i++){
        matrix[i][0].arrow = up;
        matrix[i][0].operation = i;
    }

    for (int j = 0; j <= len_b; j++){
        matrix[0][j].arrow = leftr;
        matrix[0][j].operation = j;
    }

    for (int i = 1; i <= len_a; i++){
        for (int j = 1; j <= len_b; j++){
            if (a[i - 1] == b[j - 1]){
                matrix[i][j].arrow = none;
                matrix[i][j].operation = matrix[i-1][j-1].operation;
            }
            else{
                int min = findMin(matrix[i - 1][j - 1].operation, matrix[i - 1][j].operation, matrix[i][j - 1].operation);
                if(min == matrix[i - 1][j - 1].operation){
                    matrix[i][j].arrow = diagonal;
                }
                else if(min == matrix[i - 1][j].operation){
                    matrix[i][j].arrow = up;
                }
                else{
                    matrix[i][j].arrow = leftr;
                }
                
                matrix[i][j].operation = 1 + min;
            }
        }
    }

    int answer = matrix[len_a][len_b].operation;
    return answer;
}

void printPath(int x, int y){
    if( x<0 || y<0){
        return;
    }
    if(matrix[x][y].arrow == diagonal){
        printPath(x-1, y-1);
    }
    else if(matrix[x][y].arrow == up){
        printPath(x-1, y);
    }
    else{
        printPath(x, y-1);
    }

    if(matrix[x][y].arrow == none){
        cout<<"No oeration needed"<<endl;
    }
    else if(matrix[x][y].arrow == leftr){
        cout<<"insert"<<endl;
    }
    else if(matrix[x][y].arrow == up){
        cout<<"delete"<<endl;
    }
    else cout<<"replace"<<endl;
    //cout<<matrix[a][b].arrow<<"->";
}

int main(){
    

    cout << "Total operations: " << findDistance(a, b)<<endl;
    printPath(strlen(a), strlen(b));
    cout<<endl;
    return 0;
}
