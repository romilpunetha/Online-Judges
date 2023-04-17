#include <bits/stdc++.h>
#define tr1(x) cerr << #x << ":\t" << x << endl
#define tr2(x, y) cerr << #x << ":\t" << x << "\t|\t" << #y << ":\t" << y << endl
#define tr3(x, y, z) cerr << #x << ":\t" << x << "\t|\t" << #y << ":\t" << y << "\t|\t" << #z << ":\t" << z << endl
#define tr4(a, b, c, d) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << endl
#define tr5(a, b, c, d, e) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << "\t|\t" << #e << ":\t" << e << endl
#define tr6(a, b, c, d, e, f) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << "\t|\t" << #e << ":\t" << e << "\t|\t" << #f << ":\t" << f << endl
#define ff first
#define ss second
using namespace std;
typedef long long ll;
int mod = 1e9 + 7;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int test;
    cin >> test;
    while (test--) {
        int n, m;
        cin >> n >> m;
        vector<vector<ll> > dp(210, vector<ll>(210, 0));
        vector<pair<int, int> > arr(n);
        for (auto &it : arr) cin >> it.ff >> it.ss;
        dp[n][0] = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= m; j++) {
                for (int k = arr[i].ff; k <= arr[i].ss; k++) {
                    if (j - k >= 0) {
                        dp[i][j] += dp[i + 1][j - k];
                        dp[i][j] %= mod;
                    }
                }
            }
        }
        cout << dp[0][m] << endl;
    }
    return 0;
}
