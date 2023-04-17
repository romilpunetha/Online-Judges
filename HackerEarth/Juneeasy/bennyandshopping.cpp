#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool all0(string &s) {
    int i = 0;
    while (s[i] != '\0') {
        if (s[i] != '0') return false;
        i++;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    getline(cin, s);
    while (getline(cin, s)) {
        int j = 0;
        string res;
        while (s[j++] != '$')
            ;
        while (s[j] != '\0' && (s[j] == '0' || s[j] == ' ')) j++;
        while (s[j] != '\0' && (s[j] == ' ' || (s[j] >= '0' && s[j] <= '9'))) {
            if (s[j] != ' ') res += s[j];
            j++;
        }
        if (all0(res)) res = "0";
        cout << "$" << res << endl;
    }
    return 0;
}
