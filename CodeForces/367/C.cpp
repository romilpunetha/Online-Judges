#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    vector<vector<ll> > dp(n + 1, vector<ll>(2));
    vector<vector<string> > str(n + 1, vector<string>(2));
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) {
        string t;
        cin >> t;
        str[i][0] = t;
        reverse(t.begin(), t.end());
        str[i][1] = t;
    }
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i][1] = 1e16;
        if (str[i][0] >= str[i - 1][1]) dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        if (str[i][0] >= str[i - 1][0]) dp[i][0] = min(dp[i][0], dp[i - 1][0]);
        if (str[i][1] >= str[i - 1][1]) dp[i][1] = min(dp[i][1], dp[i - 1][1]);
        if (str[i][1] >= str[i - 1][0]) dp[i][1] = min(dp[i][1], dp[i - 1][0]);
        dp[i][1] += arr[i];
    }
    if (min(dp[n][0], dp[n][1]) > 5e15)
        cout << "-1" << endl;
    else
        cout << (min(dp[n][0], dp[n][1])) << endl;
    return 0;
}
