#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

typedef struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *next;
}nd;

struct TreeNode* newNode(int data){
    TreeNode *ptr=(TreeNode*)malloc(sizeof(TreeNode));
    ptr->val=data;
    ptr->left=NULL;
    ptr->right=NULL;
    return ptr;

}

void inorder(TreeNode *root){
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->val<<endl;
    inorder(root->right);
}

TreeNode *bst(TreeNode *root,int val){
    TreeNode *ptr=newNode(val);
    if(!root)return ptr;
    TreeNode *temp=root,*t;
    while(root){
        t=root;
        if(val>root->val)
            root=root->right;
        else if(val<root->val)
            root=root->left;
    }
    if(val>t->val) t->right=ptr;
    else t->left=ptr;
    return temp;
}

void util(TreeNode *root1,TreeNode *root2){
    if(!root1 || !root2)return;
    stack<TreeNode*>s1,s2;
    while(1){
        while(root1){s1.push(root1);root1=root1->left;}
        while(root2){s2.push(root2);root2=root2->left;}
        if(!(s1.empty() || s2.empty())){
            root1 = s1.top();root2 = s2.top();
            if(root1->val == root2->val){
                cout<<root1->val<<" ";
                s1.pop();root1=root1->right;
                s2.pop();root2=root2->right;
            }
            else if(root2->val < root1->val){
                s2.pop();
                root2 = root2->right;
                root1=NULL;
            }
            else{
                s1.pop();
                root1=root1->right;
                root2=NULL;
            }
        }
        else break;
    }
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    TreeNode *root1=NULL;
    int val;
    while(1){
        cin>>val;
        if(val==-1)break;
        root1=bst(root1,val);
    }
    inorder(root1);
    cout<<endl;
    TreeNode *root2=NULL;
    while(1){
        cin>>val;
        if(val==-1)break;
        root2=bst(root2,val);
    }
    inorder(root2);
    cout<<endl;
    util(root1,root2);
    return 0;
}

