#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef unsigned long long ll;
ll l, r, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> l >> r >> k;
    ll res = 1;
    int flag = 0;
    while (res <= r) {
        if (res >= l) cout << res << " ", flag++;
        if (r / res >= k)
            res *= k;
        else
            break;
    }
    if (!flag) cout << -1;
    return 0;
}
