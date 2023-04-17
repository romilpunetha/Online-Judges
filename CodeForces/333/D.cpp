#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
vector<int> tree(1e6 + 10, 0), arr(1e6, 0);

void build(int node, int start, int endd) {
    if (start == endd)
        tree[node] = 0;
    else if (endd - start == 1) {
        tree[node] = abs(arr[endd] - arr[start]);
        return;
    } else {
        int mid = (start + endd) >> 1;
        build(2 * node + 1, start, mid);
        build(2 * node + 2, mid + 1, endd);
        int p = tree[2 * node + 1];
        int q = tree[2 * node + 2];
        int r = abs(arr[(start + endd) / 2] - arr[(start + endd) / 2 + 1]);
        tree[node] = p + q + r + max(p, max(q, r));
    }
}

int query(int node, int start, int endd, int l, int r) {
    if (start > r || endd < l) return 0;
    if (start >= l && endd <= r) return tree[node];
    int mid = (start + endd) >> 1;
    int p = query(2 * node + 1, start, mid, l, r);
    int q = query(2 * node + 2, mid + 1, endd, l, r);
    int ra = abs(arr[mid] - arr[mid + 1]);
    return p + q + ra + max(p, max(q, ra));
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    int q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> arr[i];
    build(0, 0, n - 1);
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << query(0, 0, n - 1, l, r) << endl;
    }
    return 0;
}
