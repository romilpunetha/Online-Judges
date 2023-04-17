#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a, b, c;
    cin >> a >> b >> c;
    if (a == b) {
        cout << "YES" << endl;
        return 0;
    }
    if (c == 0) {
        cout << "NO" << endl;
        return 0;
    }
    if ((b - a) % c == 0) {
        ll n = ((b - a) / c) + 1;
        if (n > 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    } else
        cout << "NO" << endl;
    return 0;
}
