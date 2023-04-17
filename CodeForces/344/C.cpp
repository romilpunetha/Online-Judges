#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m, i;
    cin >> n >> m;
    vector<int> arr(n), mgr(n, 0), task(n, 0), ans(n);
    for (i = 0; i < n; i++) cin >> arr[i];
    for (i = 1; i <= m; i++) {
        int t, r;
        cin >> t >> r, mgr[r - 1] = i, task[r - 1] = t;
    }
    i = n - 1;
    while (i >= 0 && mgr[i] == 0) ans[i] = arr[i], i--;
    int start = 0, end = i, curr = 0;
    sort(arr.begin(), arr.begin() + i + 1);
    while (start <= end) {
        curr = i;
        while (i >= 0 && start <= end && mgr[i] <= mgr[curr]) ans[i--] = task[curr] == 1 ? arr[end--] : arr[start++];
    }
    for (auto it : ans) cout << it << " ";
    cout << endl;
    return 0;
}
