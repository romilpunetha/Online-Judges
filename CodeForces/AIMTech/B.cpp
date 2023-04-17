#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
ll n, a, ans = 0;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> a;
    vector<ll> x(n);
    if (n == 1) return cout << 0 << endl, 0;
    for (auto &it : x) cin >> it;
    sort(x.begin(), x.end());
    ans = min(min(abs(x[0] - a), abs(x[n - 2] - a)) + x[n - 2] - x[0], min(abs(x[1] - a), abs(x[n - 1] - a)) + x[n - 1] - x[1]);
    cout << ans << endl;
    return 0;
}
