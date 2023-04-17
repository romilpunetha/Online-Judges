#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int size, k, i;
    cin >> size >> k;
    vector<int> arr(size);
    map<int, int> m;
    int cnt = 0;
    for (i = 0; i < size; i++) {
        cin >> arr[i];
        if (!arr[i]) m[cnt++] = i;
    }
    if (k > cnt - 1) {
        cout << size << endl;
        for (int i = 0; i < size; i++) {
            cout << 1 << " ";
        }
        cout << endl;
        return 0;
    }
    vector<int> pre(size, 0), suf(size, 0);
    for (i = 1, pre[0] = arr[0]; i < size; i++) pre[i] = arr[i] == 0 ? 0 : pre[i - 1] + arr[i];
    if (k == 0) {
        int mxx = 0;
        for (auto it : pre) mxx = max(mxx, it);
        cout << mxx << endl;
        for (auto it : arr) cout << it << " ";
        cout << endl;
        return 0;
    }
    for (i = size - 2, suf[size - 1] = arr[size - 1]; i >= 0; i--) suf[i] = arr[i] == 0 ? 0 : arr[i] + suf[i + 1];
    int p = -1, q = -1, mx = INT_MIN;
    i = 0;
    int start = m[i], end = m[i + k - 1];
    while (i + k - 1 < cnt) {
        if (mx < (end - start + 1 + ((start - 1) >= 0 ? pre[start - 1] : 0) + ((end + 1) < size ? suf[end + 1] : 0))) {
            mx = end - start + 1 + ((start - 1) >= 0 ? pre[start - 1] : 0) + ((end + 1) < size ? suf[end + 1] : 0);
            p = start, q = end;
        }
        i++;
        start = m[i];
        end = m[i + k - 1];
    }
    for (i = p; i <= q; i++) {
        if (!arr[i]) arr[i] = 1;
    }
    cout << mx << endl;
    for (auto it : arr) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
