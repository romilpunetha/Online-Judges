#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

typedef struct trie {
    typedef struct node {
        node *arr[2];
        int cnt, val;
        node() {
            cnt = 0, val = 0;
            arr[0] = NULL;
            arr[1] = NULL;
        }
    } node;

    node *root;
    trie() {
        root = new node();
    }

    void insert(int num) {
        node *temp = root;
        for (int i = 30; i >= 0; i--) {
            if (temp->arr[(num >> i) & 1] == NULL) temp->arr[(num >> i) & 1] = new node();
            temp = temp->arr[(num >> i) & 1];
        }
        temp->val = num;
        temp->cnt++;
    }

    int query(int num) {
        node *temp = root;
        for (int i = 30; i >= 0; i--) {
            if (temp->arr[1 - ((num >> i) & 1)] != NULL)
                temp = temp->arr[1 - ((num >> i) & 1)];
            else
                temp = temp->arr[((num >> i) & 1)];
        }
        whats(temp->val);
        return temp->val;
    }

    void erase(int num) {
        stack<node *> st;
        node *temp = root;
        int i = 30;
        while (i >= 0) {
            temp = temp->arr[((num >> i) & 1)];
            st.push(temp);
            i--;
        }
        temp->cnt--;
        if (temp->cnt == 0) {
            cout << "deleting" << endl;
            while (!st.empty()) {
                temp = st.top();
                st.pop();
                whats(temp);
                whats(temp->arr[0]);
                whats(temp->arr[1]);
                if (temp->arr[0] == NULL && temp->arr[1] == NULL) {
                    cout << "flag\n";
                    delete temp;
                    temp = NULL;
                } else
                    break;
            }
        }
    }
} trie;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    trie tt;
    tt.insert(0);
    while (n--) {
        char c;
        int t;
        cin >> c >> t;
        if (c == '+') tt.insert(t);
        if (c == '-') tt.erase(t);
        if (c == '?') cout << (t ^ tt.query(t)) << endl;
    }
    return 0;
}
