// Implemetation of Trie
#include<bits/stdc++.h>
using namespace std;
class Node{
    private:
    Node *charcter[26];
    bool flag;
    public:
    Node()
    {
        for(int i=0;i<26;i++)
        {
            charcter[i]=nullptr;
        }
        flag=false;
    }
    bool check(char ch)
    {
       return charcter[ch-'a']!=nullptr;
    }
    void insert(char ch,Node* node)
    {
        charcter[ch-'a']=node;
    }
    Node* getNext(char ch)
    {
        return charcter[ch-'a'];
    }
    void end()
    {
        flag=true;
    }
    bool returnEnd()
    {
        return flag;
    }
};
class Trie {
public:
    Node *root=new Node();
    void insert(string word) {
        Node *temp=root;
        for(char i:word)
        {
            if(temp->check(i)==false)
            {
            Node *node=new Node();
            temp->insert(i,node);
            }
            temp=temp->getNext(i);
        }
        temp->end();
    }
    
    bool search(string word) {
        Node *temp=root;
        for(char i:word)
        {
            if(temp->check(i)==false)
            return false;
            temp=temp->getNext(i);
        }
        return temp->returnEnd();
    }
    
    bool startsWith(string prefix) {
        Node *temp=root;
        for(char i:prefix)
        {
            if(temp->check(i)==false)
            return false;
            temp=temp->getNext(i);
        }
        return true;
    }
};
int main()
{
    vector<string> words={"abcd","xyz","abcdef","ab"};
    Trie *trie=new Trie();
    for(auto i:words)
        trie->insert(i);
    
}