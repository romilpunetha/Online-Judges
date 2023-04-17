#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
vector<ll> bit(1e6 + 10, 0);
vector<ll> arr;
ll n, q, bs, currentR, currentL, cnt = 0;

typedef struct node {
    ll l, r, i, ans;
} node;

bool mo(const node &a, const node &b) {
    if (a.r / bs > b.r / bs)
        return true;
    else if (a.r / bs == b.r / bs)
        return a.l / bs > b.l / bs;
    return false;
}

void update(int ind, int val) {
    while (ind <= 1e6) {
        bit[ind] += val;
        ind += ind & -ind;
    }
}

ll query(int ind) {
    ll sum = 0;
    while (ind) {
        sum += bit[ind];
        ind -= ind & -ind;
    }
    return sum;
}

void compress(vector<ll> &a) {
    vector<ll> tmp = a;
    sort(tmp.begin(), tmp.end());
    unordered_map<ll, ll> mp;
    mp.reserve(n);
    for (int i = 0; i < n; i++) {
        mp[tmp[i]] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        arr[i] = mp[arr[i]];
    }
}

void add(int a) { update(a, 1); }

void remove(int a) { update(a, -1); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    bs = sqrt(n);
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    compress(arr);
    vector<node> qry(q);
    vector<ll> ans(q);
    for (int i = 0; i < q; i++) {
        cin >> qry[i].l >> qry[i].r;
        qry[i].l--, qry[i].r--;
        qry[i].i = i;
    }
    sort(qry.begin(), qry.end(), mo);
    currentR = n - 1, currentL = n;
    for (int i = 0; i < q; i++) {
        while (currentL > qry[i].l) {
            --currentL;
            cnt += query(arr[currentL] - 1);
            add(arr[currentL]);
        }
        while (currentL < qry[i].l) {
            cnt -= query(arr[currentL] - 1);
            remove(arr[currentL]);
            currentL++;
        }
        while (currentR > qry[i].r) {
            remove(arr[currentR]);
            cnt -= currentR - currentL - query(arr[currentR]);
            currentR--;
        }
        while (currentR < qry[i].r) {
            currentR++;
            cnt += currentR - currentL - query(arr[currentR]);
            add(arr[currentR]);
        }
        ans[qry[i].i] = cnt;
    }
    for (auto it : ans) cout << it << endl;
    return 0;
}
