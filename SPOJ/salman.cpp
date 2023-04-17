// {{{ #includes
#include <limits.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// }}}
// {{{ #define
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define um unordered_map
#define clear(x) memset((x), 0, sizeof((x)))
#define fill(x, y) memset((x), y, sizeof((x)))
#define si(x) \
    int x;    \
    scan(x);
#define sl(x) \
    ll x;     \
    scan(x);
#define FOR(i, x, y) for (ll i = (x); i <= (y); ++i)
#define ROF(i, x, y) for (ll i = (y); i >= (x); --i)
#define sz(a) int((a).size())
#define len(a) int((a).length())
#define foreach(i, c) for (auto i = (c).begin(); i != (c).end(); i++)
#define all(x) (x).begin(), (x).end()
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define lcm(x, y) (((x) / gcd((x), (y))) * (y))
#define abs(x) ((x) < 0 ? -(x) : (x))
#define sq(x) ((x) * (x))
#define gc getchar_unlocked
#define pc putchar_unlocked
using namespace std;
// }}}
// {{{ typedefs
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, int> psi;
typedef pair<int, string> pis;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
const ll inf = 2147383647;
// }}}
// {{{ fast I/O
template <typename T>
inline void scan(T &x) {
    bool neg = false;
    x = 0;
    int c = gc();
    for (; (c < 48 || c > 57) && c != '-'; c = gc())
        ;
    if (c == '-') {
        neg = true;
        c = gc();
    }
    for (; c > 47 && c < 58; c = gc()) {
        x = (x << 1) + (x << 3) + c - 48;
    }
    x = neg == true ? -x : x;
}
template <typename T>
inline void write(T x) {
    bool neg = false;
    char buffer[200];
    int i = 0;
    if (x < 0) {
        x = -x;
        neg = true;
    }
    do {
        buffer[i++] = (x % 10) + '0';
        x /= 10;
    } while (x);
    i--;
    if (neg == true) {
        i++;
        buffer[i] = '-';
    }
    while (i >= 0) pc(buffer[i--]);
    pc('\n');
}
// }}}
// {{{ display vectors
template <class T>
void display(vector<vector<T> > &arr) {
    typename vector<vector<T> >::iterator ii;
    typename vector<T>::iterator ij;
    cout << "Vector contains:" << endl;
    for (ii = arr.begin(); ii != arr.end(); ii++) {
        for (ij = (*ii).begin(); ij != (*ii).end(); ij++) {
            cout << *ij << " ";
        }
        cout << endl;
    }
    cout << endl;
}
template <class T>
void display(vector<T> &arr) {
    typename vector<T>::iterator it;
    cout << "Vector contains:" << endl;
    for (it = arr.begin(); it != arr.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
// }}}

struct segtree {
    struct comp {
        ll sum;
        ll min;
        ll lazy;
        comp() {
            sum = 0;
            min = LONG_MAX;
            lazy = 0;
        }
    };
    vector<comp> tree;
    vl begin, end;
    ll size;
    ll id;
    segtree(ll n) {
        id = 0;
        size = n + 1;
        begin.assign(size, 0);
        end.assign(size, 0);
        vector<comp>(2 * size).swap(tree);
        // vector<comp>(400005).swap(tree);
    }
    void display() {
        vector<comp>::iterator it;
        cout << "Vector contains:" << endl;
        for (it = tree.begin(); it != tree.end(); it++) {
            cout << "sum : " << it->sum << " min : " << it->min << " lazy : " << it->lazy << endl;
        }
        cout << endl;
    }
    void create(ll node, vector<list<ll> > &g, vl &arr) {
        begin[node] = id;
        tree[size + id].sum = arr[node];
        tree[size + id++].min = arr[node];
        list<ll>::iterator it;
        foreach (it, g[node]) {
            create(*it, g, arr);
        }
        end[node] = id - 1;
    }
    void build(vector<list<ll> > &g, vl &arr) {
        create(1, g, arr);
        ROF(i, 1, size - 1) {
            tree[i].sum += tree[i << 1].sum + tree[i << 1 | 1].sum;
            tree[i].min = min(tree[i << 1].min, tree[i << 1 | 1].min);
        }
    }
    void update(ll start, ll end, ll low, ll high, ll pos, ll delta) {
        // cout<<"start end low high pos : "<<start<<" "<<end<<" "<<low<<" "<<high<<" "<<pos<<"\n\n";
        if (low > high)
            return;
        if (tree[pos].lazy != 0) {
            // cout<<"lazy "<<pos<<endl;
            tree[pos].sum += (tree[pos].lazy * (ll)(high - low + 1));
            tree[pos].min += tree[pos].lazy;
            if (low != high) {
                tree[pos << 1].lazy += tree[pos].lazy;
                tree[pos << 1 | 1].lazy += tree[pos].lazy;
            }
            tree[pos].lazy = 0;
        }
        if (start > high || end < low) return;
        if (start <= low && end >= high) {
            // cout<<"overlap : "<<low<<" "<<high<<endl;
            tree[pos].sum += (delta * (ll)(high - low + 1));
            if (low != high) {
                tree[pos << 1].lazy += delta;
                tree[pos << 1 | 1].lazy += delta;
            }
            return;
        }
        ll mid = (low + high) / 2;
        update(start, end, low, mid, pos << 1, delta);
        update(start, end, mid + 1, high, pos << 1 | 1, delta);
        tree[pos].sum = tree[pos << 1].sum + tree[pos << 1 | 1].sum;
        tree[pos].min = min(tree[pos << 1].min, tree[pos << 1 | 1].min);
    }

    pll query(ll start, ll end, ll low, ll high, ll pos) {
        // cout<<"start end low high pos : "<<start<<" "<<end<<" "<<low<<" "<<high<<" "<<pos<<endl;
        if (tree[pos].lazy != 0) {
            tree[pos].sum += (tree[pos].lazy * (ll)(high - low + 1));
            tree[pos].min += tree[pos].lazy;
            if (low != high) {
                tree[pos << 1].lazy += tree[pos].lazy;
                tree[pos << 1 | 1].lazy += tree[pos].lazy;
            }
            tree[pos].lazy = 0;
        }
        if (start > high || end < low) return mp(-1, LONG_MAX);
        if (start <= low && end >= high) {
            return mp(tree[pos].sum, tree[pos].min);
        }
        ll mid = (low + high) / 2;
        pll a = query(start, end, low, mid, pos << 1);
        pll b = query(start, end, mid + 1, high, pos << 1 | 1);
        if (a.ff != -1 && b.ff != -1) {
            return mp((a.ff + b.ff), min(a.ss, b.ss));
        } else if (a.ff == -1) {
            return b;
        } else {
            return a;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    si(test);
    FOR(w, 1, test) {
        cout << "Case " << w << ":" << endl;
        si(n);
        si(q);
        vector<list<ll> > g(n + 1);
        vl arr(n + 1);
        segtree st(n);
        FOR(i, 1, n) {
            si(p);
            si(s);
            arr[i] = s;
            g[p].pb(i);
        }
        st.build(g, arr);
        FOR(i, 1, q) {
            si(cases);
            sl(id);
            ll x = st.begin[id];
            ll y = st.end[id];
            if (cases == 1) {
                ll res = st.query(x, y, 0, n - 1, 1).ff;
                st.display();
                write(res);
            } else {
                ll m = st.query(x, y, 0, n - 1, 1).ss;
                // cout<<"min : "<<m<<endl;
                st.update(x, y, 0, n - 1, 1, m);
                // st.display();
            }
        }
    }
    return 0;
}
