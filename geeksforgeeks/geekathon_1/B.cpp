#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int test;
    cin >> test;
    while (test--) {
        ll m, n, ans = 0;
        cin >> n >> m;
        vector<long double> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            long double dist = sqrt((x * x) + (y * y));
            int t = upper_bound(arr.begin(), arr.end(), dist, [](long double a, long double b) { return a > b; }) - arr.begin();
            ans += t;
        }
        cout << ans << endl;
    }
    return 0;
}
