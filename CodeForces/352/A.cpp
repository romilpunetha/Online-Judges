#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 0;
    cin >> n;
    {
        int range = 9, cnt = 1;
        while (n > range) {
            n -= range;
            range *= 20;
            cnt++;
        }
        int start = pow(10, cnt - 1);
        start += ((n - 1) / cnt);
        int dig = (n + cnt - 1) % cnt;
        int ans = (start / (pow(10, cnt - dig - 1)));
        ans = ans % 10;
        cout << ans << endl;
    }
    return 0;
}
