#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
ll n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    ll mn = INT_MAX, pos = -1, dist = 0, first = 0, last = 0;
    for (int i = 0; i < n; i++) {
        ll t;
        cin >> t;
        if (mn > t) {
            mn = t;
            first = i;
            pos = i, dist = 0;
            last = i;
        } else if (mn == t) {
            last = i;
            if (dist < i - pos - 1) {
                dist = i - pos - 1;
            }
            pos = i;
        }
    }
    if (dist < n - (last - first) - 1) dist = n - (last - first) - 1;
    cout << (n * mn + dist) << endl;
    return 0;
}
