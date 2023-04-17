#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s1, s2;
int l;

string check(string s) {
    int len = s.length();
    if (len == 1 || len % 2 == 1) return s;
    string s1 = check(s.substr(0, len / 2));
    string s2 = check(s.substr(len / 2));
    return s1 < s2 ? s1 + s2 : s2 + s1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s1 >> s2;
    cout << (check(s1) == check(s2) ? "YES" : "NO") << endl;
    return 0;
}
