#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    int *left, *right;
};

int main(){
    int p = 10, q= 40;
    cout<<&p<<endl;
    cout<<&q<<endl;
    struct node x, y;
    x.data = 120;
    x.left = &p;
    x.right = &q;

    cout<<x.data<<" "<<x.left<<" "<<x.right<<endl;
    y = x;
    cout<<y.data<<" "<<y.left<<" "<<y.right<<endl;


}