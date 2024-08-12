//CONSTRUCTION OF THE TREE USING BFS (BREADTH FIRST SEARCH) AND DFS (DEPTH FIRST SEARCH)

#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
    //constructor for a TreeNode creation
    TreeNode(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};
//Inorder traversal for the tree
void inorder(TreeNode *root)
{
    if(root==NULL)
    return;
    else
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);   
    }
}
//It checks breath wise and inserts into the tree
void construct_tree_using_bfs(TreeNode* root,vector<int> &nodes)
{
    queue<TreeNode*> q;
    q.push(root);
    int i=1;
    int n=nodes.size();
    TreeNode *t;
     while(!q.empty())
    {
        t=q.front();
        q.pop();
        if(i<n&&nodes[i]!=-1)
        {
            TreeNode *nn=new TreeNode(nodes[i]);
            q.push(nn);
            t->left=nn;
        }
        i++;
        if(i<n&&nodes[i]!=-1)
        {
            TreeNode *nn=new TreeNode(nodes[i]);
            q.push(nn);
            t->right=nn;
        }
        i++;
    }
}
//It checks depth wise and inserts into the tree
TreeNode* construct_tree_using_dfs(vector<int> &nodes,int i)
{
    if(i>=nodes.size()||nodes[i]==-1)
    return nullptr;
    TreeNode *root=new TreeNode(nodes[i]);
    root->left=construct_tree_using_dfs(nodes,2*i+1);
    root->right=construct_tree_using_dfs(nodes,2*i+2);
    return root;
}
TreeNode* create_a_TreeNode(int val)
{
    struct TreeNode *root;
    //creation using the constructor
    root=new TreeNode(val);
    return root;
}
int main()
{
    int n;
    cin>>n;
    vector<int> nodes;
    int a;
    //-1 for the null
    for(int i=0;i<n;i++)
    {
        cin>>a;
        nodes.push_back(a);
    }
    TreeNode *root=new TreeNode(nodes[0]);
    construct_tree_using_bfs(root,nodes);
    TreeNode *tree=construct_tree_using_dfs(nodes,0);
    inorder(tree);
    return 0;
}
