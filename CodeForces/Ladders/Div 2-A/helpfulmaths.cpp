#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    map<char, int> m;
    int len = s.size();
    for (int i = 0; i < len; i++) {
        if (s[i] != '+')
            m[s[i]]++;
    }
    string res;
    for (auto it : m) {
        for (int i = 0; i < it.second; i++) {
            res = res + it.first + '+';
        }
    }
    res.pop_back();
    cout << res << endl;
    return 0;
}
