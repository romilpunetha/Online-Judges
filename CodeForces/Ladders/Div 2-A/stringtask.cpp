#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    string res = "";
    int i = 0;
    while (s[i]) {
        s[i] = tolower(s[i]);
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y') {
            i++;
            continue;
        } else
            res = res + "." + s[i];
        i++;
    }
    cout << res << endl;
    return 0;
}
