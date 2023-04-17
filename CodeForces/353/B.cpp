#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int p, q, s, t;
        p = i;
        s = p + a - d;
        q = p + b - c;
        t = q + a - d;
        s = t + c - b;
        if (p >= 1 && q >= 1 && s >= 1 && t >= 1 && p <= n && q <= n && t <= n && s <= n)
            cnt++;
    }
    cout << (ll)cnt * n << endl;
    return 0;
}
