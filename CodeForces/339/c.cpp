#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long double ll;
const int MAX = 1e5 + 10;
ll a[MAX], b[MAX], mx = 0.0, mn = LDBL_MAX;
int n;
ll x, y, pi = 3.14159265;

ll dist(ll p, ll q) {
    return ((p - x) * (p - x) + (q - y) * (q - y));
}

ll util(ll x1, ll y1, ll x2, ll y2) {
    ll d1 = x2 - x1, d2 = y2 - y1;
    ll l = 0, r = 1;
    for (int i = 0; i < 60; i++) {
        ll ld = l + (r - l) / 3, rd = r - (r - l) / 3;
        if (dist(x1 + ld * d1, y1 + ld * d2) < dist(x1 + rd * d1, y1 + rd * d2))
            r = rd;
        else
            l = ld;
    }
    return dist(x1 + l * d1, y1 + l * d2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << setprecision(20);
    cin >> n >> x >> y;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        mx = max(mx, dist(a[i], b[i]));
        mn = min(mn, util(a[i], b[i], a[j], b[j]));
    }
    cout << pi * (mx - mn) << endl;
    return 0;
}
