#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int test;
    cin >> test;
    for (int t = 1; t <= test; t++) {
        cout << "Case #" << t << ": " << endl;
        int n, m;
        cin >> n >> m;
        vector<ll> arr(n);
        for (auto &it : arr) cin >> it;
        while (m--) {
            int l, r;
            cin >> l >> r;
            long double ans = 1.0;
            for (int i = l; i <= r; i++) {
                ans *= pow(arr[i], 1.0 / (r - l + 1));
            }
            cout << fixed << setprecision(20) << ans << endl;
        }
    }
    return 0;
}
