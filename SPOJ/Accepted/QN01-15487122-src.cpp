#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

struct Node
{
    int eof;
    int index;
    Node *arr[2];
};

struct Trie
{
    int count;
    struct Node *root;
};

typedef struct Node *node;
typedef struct Trie *trie_node;

int rep=0;

int max(int a,int b)
{
    return (a>b?a:b);
}

node create_node()
{
    node temp=new Node;
    temp->eof=0;
    temp->arr[0]=NULL;
    temp->arr[1]=NULL;
    return temp;
}

trie_node create_trie()
{
    trie_node temp=new Trie;
    temp->count=0;
    temp->root=create_node();
    return temp;
}

void insert(trie_node trie,int pre,int index)
{
    //   cout<<"inserting "<<pre<<endl;
    int val=0;
    unsigned int num=1<<31;
    trie->count++;
    node temp=trie->root;
    for(int i=31;i>=0;i--)
    {
        val=pre & num;
        val=val>>i;
        //     cout<<"val= "<<val<<endl;
        num=num>>1;
        if(temp->arr[val]==NULL)
        {
            temp->arr[val]=create_node();
        }
        temp=temp->arr[val];
    }
    temp->index=index;
    temp->eof=pre;
}

int find(trie_node trie,int pre)
{
    int val=0;
    unsigned int num=1<<31;
    node temp=trie->root;
    for(int i=31;i>=0;i--)
    {
        val=pre & num;
        val=val>>i;
        num=num>>1;
        if(temp->arr[val]==NULL)
        {
            return 0;
        }
        temp=temp->arr[val];
    }
    return 1;
}

int query(trie_node trie,int pre)
{
    // int xo=0;
    int val=0;
    unsigned int num=1<<31;
    node temp=trie->root;
    for(int i=31;i>=0;i--)
    {
        val=pre & num;
        val=val>>i;
        num=num>>1;
        if(temp->arr[1-val]!=NULL)
        {
            //   xo=(xo<<1)|1;
            temp=temp->arr[1-val];
        }
        else if(temp->arr[val]!=NULL)
        {
            //     xo=xo<<1;
            temp=temp->arr[val];
        }
        /*    else
              {
              return xo;
              }
              */
    }
    //    return xo;
    rep=temp->index;
    return pre^(temp->eof);
}

int main()
{
    int l,r;
    int n=0;
    int ans=0;
    int pre=0;
    cin>>n;
    if(n==0)
    {
        return 0;
    }
    trie_node trie=create_trie();
    vector<int> arr(n+1,0);
    vector<int> XOR(n+1,0);
    int l_min,r_min;
    l_min=INT_MAX;
    r_min=INT_MAX;
    //   cout<<"lmin= "<<l_min<<endl;
    /*********** This commented section of code works***************
      insert(trie,0,0);
      for(int i=0;i<=n;i++)
      {
      cin>>arr[i];
      pre=pre^arr[i];
      XOR[i]=pre;
      insert(trie,pre,i);
      if(ans<=query(trie,pre))
      {
      ans=query(trie,pre);
      }
      }
      for(int i=0;i<=n;i++)
      {
      if(query(trie,XOR[i])==ans)
      {
      l=i+1;
      r=rep;
      if(l_min>l)
      {
      l_min=l;
      r_min=r;
      }
      }
      }
      cout<<ans<<endl;
      cout<<l_min<<" "<<r_min<<endl;
      return 0;
      }
      */
    insert(trie,0,0);
    for(int i=1;i<=n;i++)
{
    cin>>arr[i];
    pre=pre^arr[i];
    XOR[i]=pre;
    insert(trie,pre,i);
    int result=query(trie,pre);
    if(ans<=result)
    {
        // cout<<"ans= "<<ans<<" and result= "<<result<<endl;
        if(result>ans)
        {
            l_min=rep+1;
            r_min=i;
        }
        else if(result==ans)
        {
            r=i;
            l=rep+1;
            if(l_min>l)
            {
                l_min=l;
                r_min=r;
            }
        }
        ans=result;
    }
}
cout<<ans<<endl;
cout<<l_min<<" "<<r_min<<endl;
return 0;
}

