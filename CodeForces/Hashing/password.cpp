#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int len = s.length();
    vector<int> kmp(len, 0);
    int j = 0, flag = 0;
    for (int i = 1; s[i]; i++) {
        if (s[i] == s[j])
            kmp[i] = ++j;
        else {
            while (j > 0 && s[j] != s[i]) j = kmp[j - 1];
            kmp[i] = (s[j] == s[i]) ? ++j : 0;
        }
    }
    int i = 0;
    if (kmp[len - 1] != 0) {
        for (i = 0; i < len - 1; i++) {
            flag = (kmp[i] == kmp[len - 1]) ? kmp[len - 1] : 0;
            if (flag) break;
        }
        if (!flag) {
            flag = kmp[kmp[len - 1] - 1];
        }
    }
    cout << (flag ? s.substr(0, flag) : "Just a legend") << endl;
    return 0;
}
