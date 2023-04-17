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
#define init(x, y) memset((x),y,sizeof((x))
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
#define tr(c, i) for (auto i = (c).begin(); i != (c).end(); i++)
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
inline void scan(T& x) {
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
void display(vector<vector<T> >& arr) {
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
void display(vector<T>& arr) {
    typename vector<T>::iterator it;
    cout << "Vector contains:" << endl;
    for (it = arr.begin(); it != arr.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
// }}}

struct segtree {
    vi st;
    int size, t;
    segtree(int n) {
        size = n + 1;
        t = (int)(ceil(log2(size + 1)));
        int u = (int)(pow(2, t + 1)) - 1;
        st.assign(u, 0);
    }
    void build() {
        ROF(i, 1, size - 1) {
            st[i] = st[i << 1] + st[i << 1 | 1];
        }
    }
    void update(int index, int val) {
        int i = size + index;
        st[i] += val;
        while (i > 1) {
            st[i >> 1] = st[i] + st[i ^ 1];
            i >>= 1;
        }
    }
    int query(int val) {
        int res = 0;
        int l = size;
        int r = l + val;
        while (l < r) {
            if (l & 1) res += st[l++];
            if (r & 1) res += st[--r];
            l >>= 1;
            r >>= 1;
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    si(M);
    si(N);
    si(Q);
    vi actor(N);
    vi scene(M, 0);
    segtree tree(N);
    FOR(i, 0, N - 1) {
        scan(actor[i]);
        scene[actor[i]]++;
    }
    FOR(i, 0, M - 1) {
        tree.st[N + 1 + scene[i]]++;
    }
    tree.build();
    while (Q--) {
        si(query);
        if (query == 1) {
            si(actr);
            si(scen);
            tree.update(scene[actor[actr]], -1);
            // display(tree.st);
            scene[actor[actr]]--;
            tree.update(scene[actor[actr]], 1);
            // display(tree.st);
            tree.update(scene[scen], -1);
            // display(tree.st);
            scene[scen]++;
            tree.update(scene[scen], 1);
            // display(tree.st);
            actor[actr] = scen;
        } else {
            si(val);
            int ans = tree.query(val);
            write(ans);
        }
    }
    return 0;
}
