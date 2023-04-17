#include <bits/stdc++.h>
#define endl '\n'
#define inf INT_MAX
#define pb push_back
#define der(c, x) ((c).find(x) != (c).end())
#define base 999983
#define baseinv 943912055
#define ff first
#define ss second
#define V vector
#define L list
#define P pair
#define MP map
#define ST set
#define UM unordered_map
#define MM multimap
#define UMM unordered_multimap
#define MS multiset
#define US unordered_set
#define UMS unordered_multiset
#define PQ priority_queue
#define Graph list<int> *
#define tr1(x) cerr << #x << ": " << x << endl;
#define tr2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define tr3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define tr4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define tr5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define tr6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ldbl;

struct C {
    bool operator()(const P<ll, P<ll, ll> > &a, const P<ll, P<ll, ll> > &b) {
        if (b.ss.ss - b.ss.ff == a.ss.ss - a.ss.ff) return a.ff > b.ff;
        return a.ss.ss - a.ss.ff > b.ss.ss - b.ss.ff;
    }
};

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    ST<P<ll, P<ll, ll> >, C> st;
    while (n--) {
        ll id, z, a, b, c, d;
        cin >> id >> z >> a >> b >> c >> d;
        ll sum = a * 50 + b * 5 + c * 10 + d * 20;
        st.insert({ id, { z, sum } });
    }
    int i = 0;
    for (auto &it : st) {
        cout << it.ff << " " << it.ss.ss << endl;
        i++;
        if (i >= 5) break;
    }
    return 0;
}
