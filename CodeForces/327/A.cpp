#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    double l, n, m;
    cin >> l >> n >> m;
    cout << fixed << setprecision(15) << (l - ((m * l) / (m + n))) << endl;
    return 0;
}
