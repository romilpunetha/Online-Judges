#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;
ll ans = 0, n, mod = 1e9 + 7;
ll dp[1010][1010], arr[1010][1010];
int x[4] = { 0, 1, 0, -1 };
int y[4] = { 1, 0, -1, 0 };

bool isvalid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < n);
}

ll dfs(int i, int j) {
    if (dp[i][j] != -1) return dp[i][j];
    ll res = 0;
    for (int k = 0; k < 4; k++) {
        int p = i + x[k];
        int q = j + y[k];
        if (isvalid(p, q) && arr[i][j] > arr[p][q]) res = (res + dfs(p, q)) % mod;
    }
    return dp[i][j] = (res + 1) % mod;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < 1010; i++)
        for (int j = 0; j < 1010; j++) {
            if (i < n && j < n) cin >> arr[i][j];
            dp[i][j] = -1;
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) ans = (ans + dfs(i, j)) % mod;
    cout << ans << endl;
    return 0;
}
