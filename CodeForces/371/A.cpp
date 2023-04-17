#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
ll l1, r1, l2, r2, k;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> l1 >> r1 >> l2 >> r2 >> k;
    if (l1 > r2 || r1 < l2) return cout << 0, 0;
    ll ans = min(r1, r2) - max(l1, l2) + 1 - (k >= max(l1, l2) && k <= min(r1, r2));
    cout << ans << endl;
    return 0;
}
