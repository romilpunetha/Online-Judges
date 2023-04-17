#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int util(int temp) {
    int cnt = 0;
    while (temp) {
        if (temp & 1)
            cnt++;
        temp >>= 1;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> arr(m + 1);
    for (int i = 0; i <= m; i++) {
        cin >> arr[i];
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (util(arr[i] ^ arr[m]) <= k)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
