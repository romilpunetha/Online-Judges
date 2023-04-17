#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int n, m, ans = 0, mn;
int arr[52][52], vis[52][52];
int x[] = { 0, 1, 0, -1 };
int y[] = { 1, 0, -1, 0 };

bool is_valid(int a, int b) {
    return (a > 0 && a < n - 1 && b > 0 && b < m - 1);
}

void update(int i, int j, int k) {
    if (mn <= arr[i][j] || mn == INT_MAX) return;
    ans += mn - arr[i][j];
    arr[i][j] = mn;
    for (int t = 0; t < 4; t++) {
        int p = i + x[t];
        int q = j + y[t];
        if (is_valid(p, q) && arr[p][q] == k) update(p, q, k);
    }
}

void dfs(int i, int j, int k) {
    vis[i][j] = 1;
    if (arr[i][j] != k) return;
    for (int t = 0; t < 4; t++) {
        int p = i + x[t];
        int q = j + y[t];
        if ((arr[p][q] != k) || (!is_valid(p, q))) mn = min(arr[p][q], mn);
        if (arr[p][q] == k && is_valid(p, q) && !vis[p][q]) {
            dfs(p, q, k);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int test;
    cin >> test;
    for (int t = 1; t <= test; t++) {
        ans = 0;
        cin >> n >> m;
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        for (int k = 1; k < 1000; k++) {
            memset(vis, 0, sizeof(vis));
            for (int i = 1; i < n - 1; i++) {
                for (int j = 1; j < m - 1; j++) {
                    mn = INT_MAX;
                    if (!vis[i][j]) dfs(i, j, k), update(i, j, k);
                }
            }
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
