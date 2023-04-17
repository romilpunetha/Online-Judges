#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll arr[7], mod = 1000000007;
    cin >> arr[1] >> arr[2];
    arr[3] = arr[2] - arr[1];
    arr[4] = arr[3] - arr[2];
    arr[5] = arr[4] - arr[3];
    arr[6] = arr[5] - arr[4];
    ll q;
    cin >> q;
    q %= 6;
    q = q == 0 ? 6 : q;
    ll ans = arr[q] % mod;
    ans = ans < 0 ? ans + mod : ans;
    cout << ans << endl;
    return 0;
}
