#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, t, prev = 0, ans = 0;
    cin >> n;
    while (n--) {
        cin >> t;
        ans += prev >= t ? prev - t + 2 : t - prev + 2;
        prev = t;
    }
    cout << ans - 1 << endl;
    return 0;
}
