#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll ans = 0;
    vector<ll> arr(3);
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr.begin(), arr.end());
    arr[1] += arr[0];
    if (arr[1] > arr[2]) swap(arr[1], arr[2]);
    if (arr[2] >= 2 * arr[1])
        ans += arr[1];
    else {
        ll diff = arr[2] - arr[1];
        ans += diff;
        arr[2] -= 2 * diff;
        arr[1] -= diff;
        ans += (arr[2] + arr[1]) / 3;
    }
    cout << ans << endl;
    return 0;
}
