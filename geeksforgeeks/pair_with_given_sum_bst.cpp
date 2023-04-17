#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    struct TreeNode *next;
} nd;

struct TreeNode *newNode(int data) {
    TreeNode *ptr = (TreeNode *)malloc(sizeof(TreeNode));
    ptr->val = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

void inorder(TreeNode *root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

TreeNode *bst(TreeNode *root, int val) {
    TreeNode *ptr = newNode(val);
    if (!root) return ptr;
    TreeNode *temp = root, *t;
    while (root) {
        t = root;
        if (val > root->val)
            root = root->right;
        else if (val < root->val)
            root = root->left;
    }
    if (val > t->val)
        t->right = ptr;
    else
        t->left = ptr;
    return temp;
}

bool util(TreeNode *root, int k) {
    if (!root) return false;
    stack<TreeNode *> st1, st2;
    TreeNode *l = root->left, *r = root->right;
    st1.push(root);
    st2.push(root);
    while (1) {
        while (l) {
            st1.push(l);
            l = l->left;
        }
        while (r) {
            st2.push(r);
            r = r->right;
        }
        if (st1.top() == st2.top()) return 0;
        if (st1.top()->val + st2.top()->val == k)
            return 1;
        else if (st1.top()->val + st2.top()->val < k) {
            r = NULL;
            l = st1.top()->right;
            st1.pop();
        } else {
            l = NULL;
            r = st2.top()->left;
            st2.pop();
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int val, k;
    TreeNode *root = NULL;
    while (1) {
        cin >> val;
        if (val == -1) break;
        root = bst(root, val);
    }
    inorder(root);
    cout << endl;
    cin >> k;
    cout << util(root, k) << endl;
    return 0;
}
