#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, sum = 0, mn = LONG_MAX, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        sum += temp;
        if (temp % 2 != 0) cnt++, mn = min(mn, temp);
    }
    if (cnt % 2 != 0) sum -= mn;
    cout << sum << endl;
    return 0;
}
