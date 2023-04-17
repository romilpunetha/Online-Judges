#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;

ll dp[100][100];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        memset(dp, 0, sizeof(dp));
        dp[n][0] = 1;
        for (int i = n; i >= 0; i--) {
            for (int j = 30; j >= 0; j--) {
                if (dp[i][j]) {
                    if (j) dp[i][j - 1] += dp[i][j];
                    if (i) dp[i - 1][j + 1] += dp[i][j];
                }
            }
        }
        cout << dp[0][0] << endl;
    }
    return 0;
}
