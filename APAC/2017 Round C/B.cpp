#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int test;
    cin >> test;
    for (int tst = 1; tst <= test; tst++) {
        int r, c, k;
        cin >> r >> c >> k;
        vector<vector<int> > grid(3010, vector<int>(3010, 1));
        for (int i = 0; i <= r; i++) grid[i][0] = 0;
        for (int i = 0; i <= c; i++) grid[0][i] = 0;
        for (int i = 0; i < k; i++) {
            int p, q;
            cin >> p >> q;
            p++, q++;
            grid[p][q] = 0;
        }
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (grid[i][j]) grid[i][j] = min(grid[i - 1][j], min(grid[i - 1][j - 1], grid[i][j - 1])) + 1;
            }
        }
        ll ans = 0;
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++) ans += grid[i][j];
        cout << "Case #" << tst << ": " << ans << endl;
    }
    return 0;
}
