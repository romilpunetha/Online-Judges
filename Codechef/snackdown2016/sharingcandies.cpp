#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    for (cin >> test; test--;) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll g = __gcd(c, d), mn = abs(a - b);
        mn = min(mn % g, g - (mn % g));
        cout << mn << endl;
    }
    return 0;
}
