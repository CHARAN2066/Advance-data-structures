//     INSERTION IN THE AVL TREE
#include<bits/stdc++.h>
using namespace std;
// Structure for the treenode
struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;//height of every node
    node(int k)
    {
        key=k;
        left=NULL;
        right=NULL;
        height=1;//intially the node is a left node so height is one
    }
};

typedef struct node Node;

Node* createNode(int key)
{
    Node *newnode=new node(key);
    return newnode;
}

//to get the height of a node
int getHeight(Node *root)
{
    if(root==NULL)
    return 0;
    else
    {
        return root->height;
    }
    
}

//balance factor is the difference betweent the height of left subtree and right subtree
int BalanceFactor(Node *node)
{
    return getHeight(node->left)-getHeight(node->right);
}

//right rotation case
Node* rightRotate(Node* y)
{
    Node *x=y->left;
    Node *temp=x->right;
    x->right=y;
    y->left=temp;
    //updation of the heights of the nodes
    y->height=1+max(getHeight(y->left),getHeight(y->right));
    x->height=1+max(getHeight(x->left),getHeight(x->right));
    return x;
}

//left rotation case
Node* leftRotate(Node *y)
{
    Node* x=y->right;
    Node *temp=x->left;
    x->left=y;
    y->right=temp;
    //updation of the heights of the nodes
    y->height=1+max(getHeight(y->left),getHeight(y->right));
    x->height=1+max(getHeight(x->left),getHeight(x->right));
    return x;
}

Node* insert(Node *root,int key)
{
    //normal insertion as the bst
    if(root==NULL)
    return createNode(key);
    else if(root->key<key)
    root->right=insert(root->right,key);
    else
    root->left=insert(root->left,key);
    //upadation of the height of the node
    root->height=1+max(getHeight(root->left),getHeight(root->right));
    //checking for the rotation 
    if(BalanceFactor(root)>1&&root->left->key>key)
    {
        // right right case
        return rightRotate(root);
    }
    else if (BalanceFactor(root)>1&&root->left->key<key)
    {
        /*  left right case */
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    else if (BalanceFactor(root)<-1&&root->right->key>key)
    {
        /* left left case */
        return leftRotate(root);
    }
    else if (BalanceFactor(root)<-1&&root->right->key<key)
    {
        /* right left case */
        root->right=rightRotate(root->left);
        return leftRotate(root);
    }
    return root;
}

//A traversal for the checking the tree
void inorder(Node *root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
}

//A traversal for the checking the tree
void preorder(Node *root)
{
    if(root==NULL)
    return; 
    cout<<root->key<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    Node* root=NULL;
    root=insert(root,1);
    root=insert(root,3);
    root=insert(root,2);
    root=insert(root,4);
    // root=insert(root,7);
    // root=insert(root,12);
    // root=insert(root,15);
    // root=insert(root,17);
    preorder(root);
}

