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

typedef struct Tree {
    typedef struct node {
        node *l, *r;
        int val;

        node() {
            l = r = NULL;
            val = -1;
        }
        node(int x) {
            l = r = NULL;
            val = x;
        }
    } node;

    node *root;

    Tree() {
        root = NULL;
    }

    node *insert(node *rt, int x) {
        if (!rt)
            rt = new node(x);
        else if (x <= rt->val)
            rt->l = insert(rt->l, x);
        else
            rt->r = insert(rt->r, x);
        return root = rt;
    }

    int get(int x, int y) {
        node *temp = root;
        while (1) {
            if (temp->val > x && temp->val > y)
                temp = temp->l;
            else if (temp->val < x && temp->val < y)
                temp = temp->r;
            else
                break;
        }
        int ans = temp->val;
        while (temp && temp->val < y) {
            ans = temp->val;
            temp = temp->r;
        }
        if (ans == y) return ans;
        return temp->val;
    }

    int get_h(node *rt) {
        if (!rt)
            return 0;
        else {
            int l = get_h(rt->l);
            int r = get_h(rt->r);
            return max(l, r) + 1;
        }
    }

    void pre(node *rt) {
        if (!rt) return;
        cout << rt->val << " ";
        pre(rt->l);
        pre(rt->r);
    }

    void in(node *rt) {
        if (!rt) return;
        in(rt->l);
        cout << rt->val << " ";
        in(rt->r);
    }

    void post(node *rt) {
        if (!rt) return;
        post(rt->l);
        post(rt->r);
        cout << rt->val << " ";
    }

} Tree;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    Tree t;
    while (n--) {
        int p;
        cin >> p;
        t.insert(t.root, p);
    }
    int p, q;
    cin >> p >> q;
    if (p > q) swap(p, q);
    cout << t.get(p, q) << endl;
    return 0;
}
