#include<bits/stdc++.h>
using namespace std;

struct node{
    char ch;
    int freq;
    struct node *left, *right;
};

struct node nodes[10000];
struct node data[10000];

struct node extract_min(int first, int last){
    struct node min;
    int index;
    min = nodes[0];
    for(int i=first; i<=last; i++){
        if(nodes[i].freq >-1 && nodes[i].freq < min.freq){
            min = nodes[i];
            index = i;
        }
    }
    nodes[index].freq = -1;
    return min;
}

struct node huffman(int size, int ptr){
    for(int i=1; i<size; i++){   //binary tree er edge number = (vertex - 1);
        struct node temp;
        temp.ch = '\0';
        temp.left = &extract_min(0, ptr-1);
        temp.right = &extract_min(0, ptr-1);
        temp.freq = temp.left->freq + temp.right->freq;
        nodes[ptr] = temp;
        ptr++;
    }

    return extract_min(0, ptr-1);
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
    for(int i = 0; i<n; i++){
        cin>>data[i].ch;
        cin>>data[i].freq;
        nodes[i] = data[i];
    }
    for(int i = 0; i<n; i++){
        cout<<nodes[i].ch<<" "<<nodes[i].freq<<endl;
    }
    struct node root = huffman(n, n);
    preorder(&root);
    return 0;
}
