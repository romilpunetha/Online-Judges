#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int n;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    vector<int> arr(n);
    for (auto &it : arr) cin >> it;
    int start = 0, i = 0, mx = 0, mn = 0, ans = 0;
    while (i < n) {
        while (i < n && arr[mx] - arr[mn] <= 1) i++, mx = arr[i] >= arr[mx] ? i : mx, mn = arr[i] <= arr[mn] ? i : mn;
        ans = max(ans, i - start);
        if (i == n) break;
        if (arr[i] == arr[mx])
            start = mn + 1, mn++;
        else
            start = mx + 1, mx++;
    }
    cout << ans << endl;
    return 0;
}
