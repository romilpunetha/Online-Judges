#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int t=0;
vector<int>pre,post;

typedef struct node{
    node *left=NULL, *right=NULL;
    int val;
    node(int t){
        val=t;
    }
}node;

node* util(int l,int r){
    if(t>pre.size())return NULL;
    node *temp=new node(pre[t++]);
    if(r<=l || t==pre.size())return temp;
    int p=-5;
    for(int i=0;i<post.size();i++){
        if(post[i]==pre[t]){p=i;break;}
    }
    if(p<l || p>r)return temp;
    temp->left=util(l,p-1);
    temp->right=util(p+1,r-1);
    return temp;
}

void inorder(node *root){
    if(!root)return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    pre.resize(n),post.resize(n);
    for(auto &it:pre)cin>>it;
    for(auto &it:post)cin>>it;
    node *root=util(0,n-1);
    inorder(root);
    return 0;
}

