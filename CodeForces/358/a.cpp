#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int n, m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    vector<ll> l(11, 0), r(11, 0);
    ll sum = 0;
    for (int i = 1; i <= 10; i++) {
        l[i] = n / 10 + (n % 10 >= i);
        r[i] = m / 10 + (m % 10 >= i);
    }
    sum += (l[1] + l[6]) * (r[4] + r[9]);
    sum += (l[2] + l[7]) * (r[3] + r[8]);
    sum += (l[3] + l[8]) * (r[2] + r[7]);
    sum += (l[4] + l[9]) * (r[1] + r[6]);
    sum += (l[5] + l[10]) * (r[10] + r[5]);
    cout << sum << endl;
    return 0;
}
