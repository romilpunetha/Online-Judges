#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int k;
    cin >> s >> k;
    int mx = 0;
    map<char, int> m;
    for (int i = 0; i < 26; i++) {
        int temp;
        cin >> temp;
        mx = max(mx, temp);
        m[(char)i + 'a'] = temp;
    }
    int len = s.size();
    ll ans = 0;
    for (int i = 1; i <= len; i++) {
        ans += i * m[s[i - 1]];
    }
    for (int i = len + 1; i <= len + k; i++) {
        ans += mx * i;
    }
    cout << ans << endl;
    return 0;
}
