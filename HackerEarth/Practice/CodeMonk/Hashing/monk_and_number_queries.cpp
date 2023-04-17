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
int n, k, q;
vector<int> parent(1e6);

typedef struct node {
    list<node *> child;
    int val = 0, height = 0;
    node(int x) {
        val = x;
    }
} node;

vector<node *> arr(1e6, NULL);

ll pows(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = (res * a) % k;
        a = (a * a) % k;
        b >>= 1;
    }
    return res;
}

void dfs(node *root, int height, int val) {
    if (!root) return;
    root->val = (val * 10 + root->val) % k;
    root->height = height + 1;
    for (auto &it : root->child) dfs(it, root->height, root->val);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> k >> q;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        arr[i] = new node(t % k);
    }
    for (int i = 0; i < n - 1; i++) {
        int t;
        cin >> t;
        t--;
        parent[i + 1] = t;
        arr[t]->child.pb(arr[i + 1]);
    }
    dfs(arr[0], 0, 0);
    while (q--) {
        int i, j;
        cin >> i >> j;
        i--, j--;
        if (i == 0) {
            if (arr[j]->val == 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        } else {
            ll v1 = arr[parent[i]]->val, h1 = arr[parent[i]]->height;
            ll v2 = arr[j]->val, h2 = arr[j]->height;
            ll res = ((v2 - (v1 * pows(10, h2 - h1)) % k) + k) % k;
            if (res == 0)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}
