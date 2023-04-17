#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;
ll ans = 0, test, len;
string s;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> test;
    while (test--) {
        cin >> s;
        ans = 1;
        len = s.length();
        vector<vector<bool> > dp(len, vector<bool>(len, 0));
        for (int i = 1; i < len; i++) dp[i][i] = 1;
        for (int i = 0; i < len; i++) {
            for (int j = i; j >= 0; j++) {
            }
        }
    }
    return 0;
}
