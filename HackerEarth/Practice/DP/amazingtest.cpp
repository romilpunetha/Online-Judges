#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;
int test, n, x, sum = 0;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> test;
    while (test--) {
        cin >> n >> x;
        sum = 0;
        vector<int> arr(n);
        vector<vector<int> > dp(n, vector<int>(1e4 + 10, 0));
        for (auto &it : arr) cin >> it, sum += it;
        dp[0][arr[0]] = 1, dp[0][0] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 1e4 + 10; j++) {
                if (dp[i - 1][j]) dp[i][arr[i] + j] = 1;
            }
            for (int j = 0; j < 1e4 + 10; j++) {
                dp[i][j] |= dp[i - 1][j];
            }
        }
        bool flag = 0;
        for (int i = 0; i <= sum; i++) {
            if (dp[n - 1][i] && max(i, sum - i) <= x) {
                flag = 1;
                break;
            }
        }
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
