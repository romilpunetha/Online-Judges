#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, l;
    cin >> n >> l;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    double mx = 0.0, prev = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, arr[i] - prev);
        prev = arr[i];
    }
    cout << fixed;
    double ans = 0;
    ans = mx / 2;
    if (arr[0] != 0) {
        ans = max((double)arr[0], ans);
    }
    if (arr[n - 1] != l) {
        ans = max((double)l - (double)arr[n - 1], ans);
    }
    cout << setprecision(10) << ans << endl;
    return 0;
}
