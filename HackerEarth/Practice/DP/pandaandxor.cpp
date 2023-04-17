#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;

int mod = 1e9 + 7;
vector<vector<ll> > dp(1e5 + 10, vector<ll>(200, 0));

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll ans = 0, n;
    cin >> n;
    vector<int> arr(n);
    for (auto &it : arr) cin >> it;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 128; j++)
            if (dp[i][j]) dp[i + 1][j ^ arr[i]] += dp[i][j];
        dp[i + 1][arr[i]]++;
        for (int j = 0; j < 128; j++) dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] % mod) % mod;
    }
    for (int i = 0; i < 128; i++) {
        ans = (ans + (((dp[n][i] - 1) * (dp[n][i])) / 2) % mod) % mod;
    }
    cout << ans << endl;
    return 0;
}
