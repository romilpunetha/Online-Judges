#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a, b, c, x, y, z, t = 0;
    cin >> a >> b >> c >> x >> y >> z;
    a -= x, b -= y, c -= z;
    t = (a > 0 ? a / 2 : a) + (b > 0 ? b / 2 : b) + (c > 0 ? c / 2 : c);
    cout << (t >= 0 ? "Yes" : "No") << endl;
    return 0;
}
