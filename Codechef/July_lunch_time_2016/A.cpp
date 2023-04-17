#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test, n, k;
    cin >> test;
    while (test--) {
        cin >> n >> k;
        int ans = 0;
        vector<int> arr(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            int t;
            cin >> t;
            if (t == i)
                arr[i] = INT_MIN;
            else
                arr[t]++;
        }
        for (auto &it : arr) ans += it >= k;
        cout << ans << endl;
    }
    return 0;
}
