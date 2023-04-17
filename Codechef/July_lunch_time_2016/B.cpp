#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll test, N, P, Q;
    cin >> test;
    while (test--) {
        cin >> N >> P >> Q;
        int ans = 0;
        vector<ll> arr(N);
        for (auto &it : arr) cin >> it;
        sort(arr.begin(), arr.end());
        for (auto &it : arr) {
            ll a = it / 2;
            if (a > Q) a = Q;
            it -= 2 * a;
            if (it <= P) ans++, P -= it, Q -= a;
        }
        cout << ans << endl;
    }
    return 0;
}
