#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int> > arr(n);
    int dp[n] = { 0 };
    for (int i = 0; i < n; i++) {
        int s, t;
        cin >> s >> t;
        arr[i] = { s, t };
    }
    sort(arr.begin(), arr.end());
    for (int i = 1; i < n; i++) {
        int diff = arr[i].first - arr[i].second;
        int index = lower_bound(arr.begin(), arr.end(), diff, [](pair<int, int> a, int b) { return a.first < b; }) - arr.begin();
        dp[i] = dp[index - 1] + i - index;
    }
    int ans = dp[n - 1];
    for (int i = 1; i < n; i++) {
        ans = min(ans, n - i + dp[i - 1]);
    }
    cout << ans << endl;
    return 0;
}
