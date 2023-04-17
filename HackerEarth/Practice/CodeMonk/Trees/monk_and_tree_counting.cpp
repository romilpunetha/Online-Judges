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

ll ans = 0, n, k, indx = 1;

typedef struct node {
    node *l, *r;
    ll val, ind;

    node() {
        l = r = NULL;
        val = -1;
        ind = 0;
    }
    node(ll x) {
        l = r = NULL;
        val = x;
        ind = 0;
    }
} node;

void pre(node *root1, node *root2, node *root3) {
    if (!root3) return;
    // tr4(root1->ind, root2->ind, root3->ind, ans);
    if (root1->ind < root2->ind && root2->ind < root3->ind && root1->val + root2->val + root3->val >= k) ans++;
    pre(root1, root2, root3->l);
    pre(root1, root2, root3->r);
}

void pre(node *root1, node *root2) {
    if (!root2) return;
    pre(root1, root2, root1);
    pre(root1, root2->l);
    pre(root1, root2->r);
}

void pre(node *root) {
    if (!root) return;
    pre(root, root);
    pre(root->l);
    pre(root->r);
}

void in(node *root) {
    if (!root) return;
    root->ind = indx++;
    in(root->l);
    in(root->r);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    vector<node *> val(n + 10, NULL);
    vector<int> parent(n + 10);
    for (int i = 1; i <= n; i++) {
        ll t;
        cin >> t;
        val[i] = new node(t);
    }
    for (int i = 2; i <= n; i++) cin >> parent[i];
    for (int i = 2; i <= n; i++) {
        if (!val[parent[i]]->l)
            val[parent[i]]->l = val[i];
        else
            val[parent[i]]->r = val[i];
    }
    node *root = val[1];
    in(root);
    // for(int i = 1; i <= n; i++) tr3(val[i]->ind, val[i]->l, val[i]->r);
    pre(root);
    cout << ans << endl;
    return 0;
}
