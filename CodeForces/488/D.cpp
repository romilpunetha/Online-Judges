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
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ldbl;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    int x[15][2], y[15][2];
    ST<int> st;
    for (int i = 0; i < n; i++) cin >> x[i][0] >> x[i][1];
    for (int i = 0; i < m; i++) cin >> y[i][0] >> y[i][1];
    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < n; i++) {
            bool a = 0, b = 0;
            for (int j = 0; j < m; j++) {
                if ((x[i][0] == y[j][0] && x[i][1] == y[j][1]) || (x[i][0] == y[j][1] && x[i][1] == y[j][0])) continue;
                if (x[i][0] == y[j][0] || x[i][0] == y[j][1]) st.insert(x[i][0]), a = 1;
                if (x[i][1] == y[j][0] || x[i][1] == y[j][1]) st.insert(x[i][1]), b = 1;
            }
            if (a && b) {
                cout << "-1" << endl;
                return 0;
            }
        }
        swap(n, m);
        swap(x, y);
    }
    if (st.empty()) cout << -1 << endl;
    if (st.size() > 1)
        cout << 0 << endl;
    else
        cout << *st.begin() << endl;
    return 0;
}
