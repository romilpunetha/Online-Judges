#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int res = 0, mx = 0, prev = -1;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t > prev)
            ++res;
        else
            res = 1;
        mx = max(res, mx);
        prev = t;
    }
    cout << mx << endl;
    return 0;
}
