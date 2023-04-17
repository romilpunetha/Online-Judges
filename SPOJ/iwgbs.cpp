#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

string add(string &a, string &b) {
    int l1 = a.length(), l2 = b.length();
    if (l1 < l2) swap(a, b), swap(l1, l2);
    string res(l1 + 2, '0');
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    a = a + "00";
    b = b + "00";
    int carry = 0;
    for (int i = 0; i <= l2 + 1; i++) {
        int num = a[i] - '0' + b[i] - '0' + carry;
        carry = num / 10;
        num %= 10;
        res[i] = num + '0';
    }
    b.pop_back();
    b.pop_back();
    if (a[l1 + 1] == '0') a.pop_back();
    if (a[l1] == '0') a.pop_back();
    if (res[l1 + 1] == '0') res.pop_back();
    if (res[l1] == '0') res.pop_back();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<string> dp(n + 1);
    dp[0] = "1";
    dp[1] = "2";
    for (int i = 2; i <= n; i++) {
        dp[i] = add(dp[i - 1], dp[i - 2]);
    }
    cout << dp[n] << endl;
    return 0;
}
