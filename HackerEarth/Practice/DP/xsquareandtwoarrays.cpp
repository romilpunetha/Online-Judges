#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;
vector<ll> a(1e5 + 10, 0), b(1e5 + 10, 0);
int n, m;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i > 1) a[i] += a[i - 2];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (i > 1) b[i] += b[i - 2];
    }
    while (m--) {
        int t, p, q;
        cin >> t >> p >> q;
        t--, p--, q--;
        ll as, bs, ae, be, l = 0, r = 0;
        if (!t) {
            as = p - 2, bs = p - 1;
            if ((q - p) % 2 == 0)
                ae = q, be = q - 1;
            else
                ae = q - 1, be = q;
        } else {
            as = p - 1, bs = p - 2;
            if ((q - p) % 2 == 0)
                be = q, ae = q - 1;
            else
                be = q - 1, ae = q;
        }
        r = (ae >= 0 ? a[ae] : 0) + (be >= 0 ? b[be] : 0);
        l = (as >= 0 ? a[as] : 0) + (bs >= 0 ? b[bs] : 0);
        assert(r - l >= 0);
        cout << r - l << endl;
    }
    return 0;
}
