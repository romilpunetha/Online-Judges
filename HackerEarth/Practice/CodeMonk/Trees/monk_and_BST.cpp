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
#define P pair
#define MP map
#define ST set
#define UM unordered_map
#define MM multimap
#define UMM unordered_multimap
#define MST multiset
#define UST unordered_set
#define UMS unordered_multiset
#define PQ priority_queue
#define Graph V<L<int> >
#define tr1(x) cerr << #x << ": " << x << endl;
#define tr2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define tr3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define tr4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define tr5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define tr6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#define all(a) (a).begin(), (a).end()
using namespace std;
// typedef long long ll;
typedef unsigned long long ll;
typedef double dbl;
typedef long double ldbl;

ll L, S, Q, t, k;

bool is_valid(ll mid) {
    ll c = (1LL << L) - 2;
    ll sum = 2 * mid * c + 2 * mid + c * c + c + (1LL << L) + (mid - 1);
    // tr4(mid, c, sum, S);
    return sum > S;
}

ll get_start() {
    ll start = 1, end = 2e18, ans = 0, mid = 0;
    while (start <= end) {
        mid = (start + end) >> 1;
        if (is_valid(mid))
            ans = mid, end = mid - 1;
        else
            start = mid + 1;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> L >> S >> Q;
    L--;
    ll start = get_start();
    ll root = L == 0 ? start : start + (1LL << (L - 1)) - 1;
    // tr2(start, root);
    while (Q--) {
        cin >> t >> k;
        if (t == 0) {
            if (k == root)
                cout << "root" << endl;
            else {
                ll t = root, l = 0;
                while (t != k && l < L) {
                    if (k <= t)
                        t -= (1LL << (L - l - 2)), cout << "l";
                    else
                        t += (1LL << (L - l - 2)), cout << "r";
                    l++;
                }
                cout << endl;
            }
        } else {
            int level = 0;
            for (int i = 0; i <= 30; i++)
                if (k >= (1LL << i)) level = i;
            ll st = start;
            for (int l = L - 2; l >= level; l--) st += (1LL << (L - l - 2));
            // tr2(level, st);
            cout << st + (1LL << (L - level)) * (k - (1LL << level)) << endl;
        }
    }
    return 0;
}
