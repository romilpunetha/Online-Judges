#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

typedef struct data {
    ll pre = 0, suf = 0, ans = 0;
} data;

vector<data> tree(1e6 + 10);
vector<ll> arr(1e5 + 10);
int n, q, t, x, y;

void ini() {
    tree.clear();
    tree.resize(1e6 + 10);
}

data combine(data l, data r, int s, int e) {
    int mid = (s + e) >> 1;
    data t;
    t.ans = max(l.ans, r.ans);
    t.pre = l.pre;
    t.suf = r.suf;
    if (arr[mid] < arr[mid + 1]) {
        t.ans = max(t.ans, l.suf + r.pre);
        if (l.pre == mid - s + 1) t.pre = l.pre + r.pre;
        if (r.suf == e - mid) t.suf = r.suf + l.suf;
    }
    return t;
}

void build(int node, int s, int e) {
    if (s == e)
        tree[node].pre = 1, tree[node].suf = 1, tree[node].ans = 1;
    else {
        int mid = (s + e) >> 1;
        build(2 * node + 1, s, mid);
        build(2 * node + 2, mid + 1, e);
        tree[node] = combine(tree[2 * node + 1], tree[2 * node + 2], s, e);
    }
}

void update(int node, int s, int e, int idx, ll val) {
    if (s == e)
        arr[idx] += val;
    else {
        int mid = (s + e) >> 1;
        if (s <= idx && idx <= mid)
            update(node * 2 + 1, s, mid, idx, val);
        else
            update(node * 2 + 2, mid + 1, e, idx, val);
        tree[node] = combine(tree[2 * node + 1], tree[2 * node + 2], s, e);
    }
}

data query(int node, int s, int e, int l, int r) {
    if (s > r || e < l) {
        data t;
        return t;
    }
    if (s >= l && e <= r) return tree[node];
    int mid = (s + e) >> 1;
    data p = query(2 * node + 1, s, mid, l, r);
    data q = query(2 * node + 2, mid + 1, e, l, r);
    data t = combine(p, q, s, e);
    return t;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int test;
    cin >> test;
    while (test--) {
        cin >> n >> q;
        ini();
        for (int i = 0; i < n; i++) cin >> arr[i];
        build(0, 0, n - 1);
        while (q--) {
            cin >> t >> x >> y;
            if (t)
                x--, update(0, 0, n - 1, x, y);
            else
                cout << query(0, 0, n - 1, x - 1, y - 1).ans << endl;
        }
    }
    return 0;
}
