/*Given two Binary Search Trees, find common nodes in them. In other words, find intersection of two BSTs.*/

#include<bits/stdc++.h>
using namespace std;
typedef struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *next;
}nd;
struct TreeNode* newNode(int data)
{
    TreeNode *ptr=(TreeNode*)malloc(sizeof(TreeNode));
    ptr->val=data;
    ptr->left=NULL;
    ptr->right=NULL;
    return ptr;

}
void inorder(TreeNode *root)
{
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->val<<endl;
    inorder(root->right);
}
TreeNode *bst(TreeNode *root,int val)
{
    TreeNode *ptr=newNode(val);
    if(!root)
        return ptr;
    TreeNode *temp=root,*t;
    while(root)
    {
        t=root;
        if(val>root->val)
            root=root->right;
        else if(val<root->val)
            root=root->left;
    }
    if(val>t->val)
        t->right=ptr;
    else
        t->left=ptr;
    return temp;
}
void KthLargest(TreeNode *root,int &count,int k){
    if(!root || count>k)return;
    KthLargest(root->right,count,k);
    count++;
    if(count==k){
        cout<<root->val<<endl;
        return ;
    }
    KthLargest(root->left,count,k);
}
int reverseInorder(TreeNode *root,int &count,int k){
    if(!root)return 0;
    int r=reverseInorder(root->right,count,k);
    if(r)return r;
    count++;
    if(count==k)return root->val;
    return reverseInorder(root->left,count,k);
}
void printCommon(TreeNode *root1,TreeNode *root2){
    if(!root1 || !root2)return;
    stack<TreeNode*>s1,s2;
    while(1){
        while(root1){
            s1.push(root1);
            root1=root1->left;
        }
        while(root2){
            s2.push(root2);
            root2=root2->left;
        }
        if((!s1.empty() && !s2.empty())){
            root1 = s1.top();
            root2 = s2.top();
            if(root1->val == root2->val){
                cout<<root1->val<<" ";
                s1.pop();
                root1=root1->right;
                s2.pop();
                root2=root2->right;
            }
            else if(root1->val < root2->val){
                s1.pop();
                root1 = root1->right;
                root2=NULL;
            }
            else{
                s2.pop();
                root2=root2->right;
                root1=NULL;
            }
        }else
            break;
    }
}
int main()
{

    TreeNode *root1=NULL;
    while(1)
    {
        int val;

        cin>>val;
        if(val==-1)break;
        root1=bst(root1,val);
    }
    inorder(root1);
    cout<<endl;

    TreeNode *root2=NULL;
    while(1)
    {
        int val;

        cin>>val;
        if(val==-1)break;
        root2=bst(root2,val);
    }
    inorder(root2);
    cout<<endl;
    printCommon(root1,root2);
    return 0;
}
