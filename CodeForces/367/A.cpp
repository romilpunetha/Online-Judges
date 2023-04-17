#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double a, b, n, x, y, dist, s, ans = DBL_MAX;
    cin >> a >> b >> n;
    while (n--) {
        cin >> x >> y >> s;
        dist = sqrt((x - a) * (x - a) + (y - b) * (y - b));
        ans = min(ans, dist / s);
    }
    cout << fixed << setprecision(20) << ans << endl;
    return 0;
}
