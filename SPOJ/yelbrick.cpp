#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;
typedef struct stone {
    ll a, b, c;
} stone;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    while (n) {
        ll mn = LLONG_MAX, ans = 0;
        vector<stone> arr(n);
        for (auto &it : arr) cin >> it.a >> it.b >> it.c, mn = min(mn, min(min(it.a, it.b), it.c));
        for (auto &it : arr) {
            ll p = it.a / mn * mn, q = it.b / mn * mn, r = it.c / mn * mn;
            ans += (p * q * r) / (mn * mn * mn);
        }
        cout << ans << endl;
        cin >> n;
    }
    return 0;
}
