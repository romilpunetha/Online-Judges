#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int size;
    cin >> size;
    vector<ll> arr(size);
    map<ll, ll> m;
    ll ans = size;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
        if (i)
            arr[i] += arr[i - 1];
        m[arr[i]]++;
        ans = min(ans, size - m[arr[i]]);
    }
    cout << ans << endl;
    return 0;
}
