#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, cr = 0, cb = 0;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        if (i & 1)
            cb += s[i] == 'b';
        else
            cr += s[i] == 'r';
    }
    int ans = min(cr, cb) + max(cr, cb) - min(cr, cb);
    cr = cb = 0;
    for (int i = 0; i < n; i++) {
        if (i & 1)
            cr += s[i] == 'r';
        else
            cb += s[i] == 'b';
    }
    ans = min(ans, min(cr, cb) + max(cr, cb) - min(cr, cb));
    cout << ans << endl;
    return 0;
}
