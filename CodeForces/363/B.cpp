#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m, n, cnt = 0;
    cin >> m >> n;
    map<int, int> x, y;
    vector<string> s(m);
    for (int i = 0; i < m; i++) {
        cin >> s[i];
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '*') x[i]++, y[j]++, cnt++;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int sum = x[i] + y[j];
            if (s[i][j] == '*') sum--;
            if (sum == cnt) return cout << "YES" << endl
                                        << i + 1 << " " << j + 1 << endl,
                                   0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
