#include<bits/stdc++.h>
using namespace std;
struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
    node(int k)
    {
        key=k;
        left=NULL;
        right=NULL;
        height=1;
    }
};
typedef struct node Node;
Node* createNode(int key)
{
    Node *newnode=new node(key);
    return newnode;
}
Node* insert(Node *root,int key)
{
    if(root==NULL)
    return createNode(key);
    else if(root->key<key)
    root->right=insert(root->right,key);
    else
    root->left=insert(root->left,key);
}
void inorder(Node *root)
{
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}
int main()
{
    Node* root=NULL;
    root=insert(root,9);
    root=insert(root,5);
    root=insert(root,13);
    root=insert(root,4);
    root=insert(root,7);
    root=insert(root,12);
    root=insert(root,15);
    root=insert(root,17);
    inorder(root);
}

