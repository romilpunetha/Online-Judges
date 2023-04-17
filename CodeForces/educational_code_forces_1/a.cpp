#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, test;
    cin >> test;
    while (test--) {
        ll res = 0;
        cin >> n;
        res = (n * (n + 1)) >> 1;
        ll num = 1;
        while (num <= n) {
            res -= num << 1;
            num <<= 1;
        }
        cout << res << endl;
    }
    return 0;
}
