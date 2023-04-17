#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll len = 0, cnt = 0, z = 0;
    cin >> len;
    vector<ll> arr(len + 1, 0);
    for (int i = 1; i <= len; i++) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    if (arr[len] % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 1; i < len; i++) {
        if (3 * arr[i] == 2 * arr[len] && i > 1)
            cnt += z;
        if (3 * arr[i] == arr[len])
            z++;
    }
    cout << cnt << endl;
}
