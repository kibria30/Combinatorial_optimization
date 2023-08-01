#include<bits/stdc++.h>
using namespace std;

struct node{
    char ch;
    int freq;
    struct node *left, *right;
};

struct node nodes[10000];
struct node data[10000];

struct node extract_min(int last){
    struct node min, temp;
    temp.ch= '\0';
    temp.freq = 100000;
    temp.left = NULL;
    temp.right = NULL;
    int index;
    min = temp;
    for(int i=0; i<=last; i++){
        if(nodes[i].freq <100000 && nodes[i].freq < min.freq){
            min = nodes[i];
            index = i;
        }
    }
    nodes[index].freq = 100000;
    return min;
}

struct node huffman(int size, struct node *root){
    int ptr = size-1;
    for(int i=1; i<size; i++){   //binary tree er edge number = (vertex - 1);
        struct node temp, x, y;
        x = extract_min(ptr);
        y = extract_min(ptr);
        temp.ch = '\0';
        temp.left = &x;
        temp.right = &y;
        temp.freq = x.freq + y.freq;
        ptr++;
        nodes[ptr] = temp;
        cout<<x.freq<<" "<<y.freq<<endl;
        cout<<"store "<<temp.freq<<"  at ptr "<<ptr<<endl;
    }
    //struct node temp2 = extract_min(ptr);
    *root = extract_min(ptr);
    //return root;
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
    // for(int i = 0; i<n; i++){
    //     cout<<nodes[i].ch<<" "<<nodes[i].freq<<endl;
    // }
    struct node root;
    huffman(n, &root);
    cout<<"from root "<<root.right->freq<<endl;
    preorder(&root);
    // for(int i = 0; i<10; i++){
    //     cout<<nodes[i].ch<<" "<<nodes[i].freq<<endl;
    // }
    return 0;
}
