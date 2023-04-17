#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int n, m, k, x, y, p1, p2;
vector<string> arr;
map<pair<int, int>, int> mp;
map<pair<int, int>, pair<int, int> > mp2;
vector<vector<bool> > visited(1000, vector<bool>(1000, 0));
int a[] = { 0, 1, 0, -1 };
int b[] = { 1, 0, -1, 0 };
int cnt = 0;

void dfs() {
    if (visited[x][y]) return;
    mp2[{ x, y }] = { p1, p2 };
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        if (arr[x + a[i]][y + b[i]] == '.') {
            x += a[i];
            y += b[i];
            dfs();
            x -= a[i];
            y -= b[i];
        } else
            cnt++;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        x--, y--;
        if (visited[x][y])
            cout << mp[mp2[{ x, y }]] << endl;
        else {
            cnt = 0, p1 = x, p2 = y, dfs(), mp[{ x, y }] = cnt;
            cout << cnt << endl;
        }
    }
    return 0;
}
