#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;
vector<ll> tree(1e6 + 10, 0), arr(1e6, 0);
int n, q;

void build(int node, int s, int e) {
    if (s == r)
        tree[node] = arr[s];
    else {
        int mid = (s + e) >> 1;
        build(2 * node + 1, s, mid);
        build(2 * node + 2, mid + 1, e);
        tree[node] = (tree[2 * node + 1] * tree[2 * node + 2]);
    }
}

void update(int node, int s, int e, int idx, int val) {
    if (s == e) {
        arr[idx] = val;
        tree[node] = val;
    } else {
        int mid = (s + 1) >> 1;
        if (s <= idx && idx <= mid)
            update(2 * node + 1, s, mid, idx, val);
        else
            update(2 * node + 2, mid + 1, e, idx, val);
        tree[node] = (tree[2 * node + 2] * tree[2 * node + 1]);
    }
}

int queryl()

    int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> arr[i];
    build(0, 0, n - 1);
    while (m--) {
        int t;
        cin >> t;
        if (t == 1) {
            int a, b;
            cin >> a >> b;
            update(0, 0, n - 1, a - 1, b);
        } else {
        }
    }
    return 0;
}
