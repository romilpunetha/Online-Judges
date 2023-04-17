#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
ll mod = 1e9 + 7, n, k, d;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k >> d;
    vector<ll> dp(n + 1, 0), dp2(n + 1, 0);
    dp[0] = 1;
    dp2[0] = 1;
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= min<ll>(k, j); i++) dp[j] += dp[j - i], dp[j] %= mod;
        for (int i = 1; i <= min<ll>(d - 1, j); i++) dp2[j] += dp2[j - i], dp2[j] %= mod;
    }
    cout << (dp[n] - dp2[n] + mod) % mod << endl;
    return 0;
}
