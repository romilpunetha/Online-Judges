#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
ll n, m, mod = 1e9 + 7, ans = 1;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    unordered_map<int, unordered_set<char> > mp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            mp[j].insert(c);
        }
    }
    for (auto &it : mp) ans = (ans * it.second.size()) % mod;
    cout << ans << endl;
    return 0;
}
