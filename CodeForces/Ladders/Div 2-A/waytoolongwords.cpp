#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    while (test--) {
        string s;
        cin >> s;
        if (s.length() <= 10) {
            cout << s << endl;
        } else {
            cout << s[0] << s.length() - 2 << s[s.length() - 1] << endl;
        }
    }
    return 0;
}
