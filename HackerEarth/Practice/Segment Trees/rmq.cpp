#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
vector<int> tree(1e6, 0), arr(1e6, 0);
int n, q;

void build(int node, int start, int endd) {
    if (start == endd)
        tree[node] = arr[start];
    else {
        int mid = (start + endd) >> 1;
        build(2 * node + 1, start, mid);
        build(2 * node + 2, mid + 1, endd);
        tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
    }
}

void update(int node, int start, int endd, int idx, int val) {
    if (start == endd)
        arr[idx] = val, tree[node] = val;
    else {
        int mid = (start + endd) >> 1;
        if (start <= idx && idx <= mid)
            update(2 * node + 1, start, mid, idx, val);
        else
            update(2 * node + 2, mid + 1, endd, idx, val);
        tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
    }
}

int query(int node, int start, int endd, int l, int r) {
    if (r < start || l > endd) return INT_MAX;
    if (start >= l && endd <= r) return tree[node];
    int mid = (start + endd) >> 1;
    int p1 = query(2 * node + 1, start, mid, l, r);
    int p2 = query(2 * node + 2, mid + 1, endd, l, r);
    return min(p1, p2);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> arr[i];
    build(0, 0, n - 1);
    for (int i = 0; i < q; i++) {
        char c;
        int l, r;
        cin >> c >> l >> r;
        if (c == 'q')
            cout << query(0, 0, n - 1, l - 1, r - 1) << endl;
        else
            update(0, 0, n - 1, l - 1, r);
    }
    return 0;
}
