#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll len, flag = 0, start, ans = 1;
    cin >> len;
    for (int i = 0; i < len; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            if (!flag)
                flag = 1, start = i;
            else
                ans *= (i - start), start = i;
        }
    }
    cout << (ans = flag ? ans : 0) << endl;
    return 0;
}
