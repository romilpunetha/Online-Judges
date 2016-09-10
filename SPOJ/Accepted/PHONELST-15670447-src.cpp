#include<iostream>
#include<vector>
#include<limits.h>
#include<stack>
#include<stdlib.h>
using namespace std;

struct Node
{
    int eof;
    Node *arr[10];
};

struct Trie
{
    struct Node *root;
};

typedef struct Node *node;
typedef struct Trie *trie_node;

node create_node()
{
    node temp=new Node;
    temp->eof=0;
    for(int i=0;i<10;i++)
    {
        temp->arr[i]=NULL;
    }
    return temp;
}

trie_node create_trie()
{
    trie_node temp=new Trie;
    temp->root=create_node();
    return temp;
}


void free_trie(stack<node> &address)
{
    while(!address.empty())
    {
        free(address.top());
        address.pop();
    }
}

void insert(trie_node trie,string input,stack<node> &address,int *flag)
{
    node temp=trie->root;
    int len=input.length();
    for(int i=0;i<len;i++)
    {
        if(temp->eof==1)
        {
            *flag=1;
        }
        if(temp->arr[input[i]-48]==NULL)
        {
            temp->arr[input[i]-48]=create_node();
            address.push(temp->arr[input[i]-48]);
        }
        temp=temp->arr[input[i]-48];
    }
    if(temp->eof==1)
    {
        *flag=1;
    }
    temp->eof=1;
    for(int i=0;i<10;i++)
    {
        if(temp->arr[i]!=NULL)
        {
            *flag=1;
            break;
        }
    }
}


int main()
{
    stack<node> address;
    string input;
    int test=0;
    int flag=0;
    cin>>test;
    for(int j=0;j<test;j++)
    {
        trie_node trie=create_trie();
        while(!address.empty())
        {
            address.pop();
        }
        flag=0;
        int st_no=0;
        cin>>st_no;
        for(int i=0;i<st_no;i++)
        {
            cin>>input;
            if(flag!=1)
            {
                insert(trie,input,address,&flag);
            }
        }
        if(flag==1)
        {
            cout<<"NO"<<endl;
            flag=0;
        }
        else
        {
            cout<<"YES"<<endl;
        }
        if(!address.empty())
        {
            free_trie(address);
        }
        free(trie->root);
        free(trie);
    }
    return 0;
}
