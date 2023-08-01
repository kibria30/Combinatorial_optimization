#include<bits/stdc++.h>
using namespace std;

struct node{
    char ch;
    int freq;
    struct node *left, *right;
};

vector<struct node> nodes;
vector<struct node> data;

struct node huffman(){
    for(int i=1; i<data.size(); i++){   //binary tree er edge number = (vertex - 1);
        struct node temp, x, y;
        sort(nodes.begin(), nodes.end());
        x = nodes[0];
        y = nodes[1];
        temp.ch = '\0';
        temp.left = &x;
        temp.right = &y;
        temp.freq = x.freq + y.freq;
        nodes.push_back(temp);
    }
    sort(nodes.begin(), nodes.end());    // sort for structure kaj ore na
    return nodes[0];
};

void preorder(struct node *root){
    if(root){
        return;
    }
    cout<<root->freq;
    preorder(root->left);
    preorder(root->right);

}

int main(){
    int n;
    cin>>n;
    struct node temp;
    for(int i = 0; i<n; i++){
        cin>>temp.ch;
        cin>>temp.freq;
        data.push_back(temp);
        data.push_back(temp);
    }
    for(auto i: nodes){
        cout<<i.ch<<" "<<i.freq<<endl;
    }
    struct node root = huffman();
    // cout<<root.freq<<endl;
    // for(int i = 0; i<13; i++){
    //     cout<<nodes[i].ch<<" "<<nodes[i].freq<<endl;
    // }
    preorder(&root);
    return 0;
}