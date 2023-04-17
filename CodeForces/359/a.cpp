#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int n, x;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x;
    ll curr = x, ans = 0;
    for (int i = 0; i < n; i++) {
        char c;
        ll num;
        cin >> c >> num;
        if (c == '+') {
            curr += num;
        } else {
            if (num <= curr)
                curr -= num;
            else
                ans++;
        }
    }
    cout << curr << " " << ans << endl;
    return 0;
}
