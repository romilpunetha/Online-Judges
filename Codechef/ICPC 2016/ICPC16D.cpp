#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
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
        int n;
        cin >> n;
        set<int> st;
        while (n--) {
            int t;
            cin >> t;
            st.insert(t);
        }
        vector<int> arr(1e6 + 10, 1);
        for (auto &i : st) {
            int j = 2;
            while (i * j <= 1e6) arr[i * j] = (arr[i * j] + arr[i]) % mod, j++;
        }
        ll ans = 0;
        for (auto &it : st) ans = (ans + arr[it]) % mod;
        cout << ans << endl;
    }
    return 0;
}
