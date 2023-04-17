#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
string s;
int i = 0;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> s;
    while (s[i] && s[i] == 'a') i++;
    if (!s[i]) {
        s[s.length() - 1] = 'z';
    }
    while (s[i] && s[i] != 'a') s[i++]--;
    cout << s << endl;
    return 0;
}
