#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        int i = 0, sum = 0, mx = 0, cnt = 0;
        while (s[i]) {
            if (s[i++] == 'R')
                sum--, cnt++;
            else
                sum++;
            if (sum < 0) sum = 0;
            mx = max(mx, sum);
        }
        if (cnt == s.length()) cnt--;
        cout << cnt + mx << endl;
    }
    return 0;
}
