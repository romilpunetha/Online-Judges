
#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
#define INT_SIZE 32
using namespace std;
typedef long long ll;
ll k = 0;
struct TrieNode {
    ll value;
    TrieNode *arr[2];
};

TrieNode *newNode() {
    TrieNode *temp = new TrieNode;
    temp->value = 0;
    temp->arr[0] = temp->arr[1] = NULL;
    return temp;
}

void insert(TrieNode *root, int pre_xor) {
    TrieNode *temp = root;
    for (int i = INT_SIZE - 1; i >= 0; i--) {
        bool val = pre_xor & (1 << i);
        if (temp->arr[val] == NULL)
            temp->arr[val] = newNode();
        temp = temp->arr[val];
    }
    temp->value = pre_xor;
}

ll query(TrieNode *root, int pre_xor) {
    TrieNode *temp = root;
    for (int i = INT_SIZE - 1; i >= 0; i--) {
        bool val = pre_xor & (1 << i);
        if (temp->arr[1 - val] != NULL)
            temp = temp->arr[1 - val];
        else if (temp->arr[val] != NULL)
            temp = temp->arr[val];
    }
    return pre_xor ^ (temp->value);
}
int maxSubarrayXOR(vector<ll> &arr, int n) {
    TrieNode *root = newNode();
    insert(root, 0);
    ll result = INT_MIN, pre_xor = 0;
    for (int i = 0; i < n; i++) {
        pre_xor = pre_xor ^ arr[i];
        insert(root, pre_xor);
        result = max(result, query(root, pre_xor ^ k));
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i], k ^= arr[i];
    cout << "Max XOR is " << maxSubarrayXOR(arr, n) << endl;
    return 0;
}
