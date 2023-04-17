#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int test;
    cin >> test;
    while (test--) {
        string s;
        cin >> s;
        int cnt = 0, len = s.length();
        char prev = s[0];
        for (int i = 1; i < len; i++) {
            if (s[i] == prev)
                cnt++;
            else
                prev = s[i];
        }
        cout << cnt << endl;
    }
    return 0;
}
