#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, ans = 0;
    cin >> n;
    vector<int> row(n, 0), col(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            ans += c == '.' ? 0 : (row[i]++ + col[j]++);
        }
    }
    cout << ans << endl;
    return 0;
}
