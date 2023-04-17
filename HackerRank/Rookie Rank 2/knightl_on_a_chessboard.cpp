#include <bits/stdc++.h>
#define endl '\n'
#define inf INT_MAX
#define pb push_back
#define present(c, x) ((c).find(x) != (c).end())
#define mod 1000000007
#define base 999983
#define baseinv 943912055
#define ff first
#define ss second
#define tr1(x) cerr << #x << ": " << x << endl;
#define tr2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define tr3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define tr4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define tr5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define tr6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int k = 1; k < n; k++) {
        for (int l = 1; l < n; l++) {
            vector<vector<int> > dp(30, vector<int>(30, 100));
            dp[0][0] = 0;
            for (int m = 0; m < 30; m++) {
                for (int i = 0; i < 30; i++) {
                    for (int j = 0; j < 30; j++) {
                        if (i - k >= 0 && j - l >= 0) dp[i][j] = min(dp[i][j], dp[i - k][j - l] + 1);
                        if (i - l >= 0 && j - k >= 0) dp[i][j] = min(dp[i][j], dp[i - l][j - k] + 1);
                        if (i - k >= 0 && j + l < 30) dp[i][j] = min(dp[i][j], dp[i - k][j + l] + 1);
                        if (i - l >= 0 && j + k < 30) dp[i][j] = min(dp[i][j], dp[i - l][j + k] + 1);
                        if (i + k < 30 && j + l < 30) dp[i][j] = min(dp[i][j], dp[i + k][j + l] + 1);
                        if (i + l < 30 && j + k < 30) dp[i][j] = min(dp[i][j], dp[i + l][j + k] + 1);
                        if (i + k < 30 && j - l >= 0) dp[i][j] = min(dp[i][j], dp[i + k][j - l] + 1);
                        if (i + l < 30 && j - k >= 0) dp[i][j] = min(dp[i][j], dp[i + l][j - k] + 1);
                    }
                }
            }
            if (dp[n - 1][n - 1] >= 100)
                cout << -1 << " ";
            else
                cout << dp[n - 1][n - 1] << " ";
        }
        cout << endl;
    }
    return 0;
}
