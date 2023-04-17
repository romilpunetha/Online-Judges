#include <bits/stdc++.h>
#define endl '\n'
#define inf INT_MAX
#define pb push_back
#define present(c, x) ((c).find(x) != (c).end())
#define mod 1000000007
#define base 999983
#define baseinv 943912055
#define ff first
#define ss second
#define tr1(x) cerr << #x << ": " << x << endl;
#define tr2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define tr3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define tr4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define tr5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define tr6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;
ll ans = 0, n, k;

unordered_map<ll, ll> mp;

typedef struct node {
    list<node *> child;
    ll val = 0;
    node(ll x) {
        val = x;
    }
} node;

void dfs(node *root, int cnt, int val) {
    int t = val ^ root->val;
    ans += mp[t ^ k];
    mp[t]++;
    for (auto &it : root->child) {
        dfs(it, cnt, (val ^ root->val));
    }
    mp[t]--;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    mp[0] = 1;
    cin >> n >> k;
    vector<ll> parent(n);
    vector<node *> ns(n, NULL);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        ns[i] = new node(t);
    }
    for (auto &it : parent) {
        cin >> it;
        it--;
    }
    for (int i = 0; i < n - 1; i++) {
        (ns[parent[i]]->child).pb(ns[i + 1]);
    }
    dfs(ns[0], 0, 0);
    cout << ans << endl;
    return 0;
}
