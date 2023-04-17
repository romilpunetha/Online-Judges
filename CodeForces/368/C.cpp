#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
ll a, b = 0, c = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a;
    if (!(a & 1)) {
        b = a / 2 * a / 2 - 1;
        c = a / 2 * a / 2 + 1;
    } else {
        b = (a * a - 1) / 2;
        c = (a * a + 1) / 2;
    }
    if (!b || !c)
        cout << -1 << endl;
    else
        cout << b << " " << c << endl;
    return 0;
}
