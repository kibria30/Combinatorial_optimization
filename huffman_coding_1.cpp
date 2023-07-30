#include<bits/stdc++.h>
using namespace std;

vector<struct node> nodes;

struct node{
    char ch;
    int freq;
    struct node *left = NULL, *right = NULL;
};

// struct node{
//     int  data;
//     struct node *left, *right;
// };

struct node* huffman(){
    //sort(nodes.begin(), nodes.end());
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    for(int i=0; i<nodes.size(); i++){
        sort(nodes.begin(), nodes.end());
        temp->left = &nodes[0];
        temp->right = &nodes[1];
        temp->freq = nodes[0].freq+ nodes[1].freq;
        temp->ch = '\0';
        nodes.push_back(*temp);
        nodes.erase(nodes.begin());
        nodes.erase(nodes.begin());
    }
    return temp;
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
    struct node data[100000];
    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>data[i].ch;
        cin>>data[i].freq;
        nodes.push_back(data[i]);
    }
    for(auto i :nodes){
        cout<<i.ch<<" "<<i.freq<<endl;
    }

    struct node *root = huffman();
    return 0;
}