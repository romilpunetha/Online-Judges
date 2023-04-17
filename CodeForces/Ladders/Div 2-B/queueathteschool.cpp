#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void swap(string &s, int i) {
    char c = s[i];
    s[i] = s[i + 1];
    s[i + 1] = c;
}

void util(string &s, int len) {
    for (int i = 0; i < len; i++) {
        if (s[i] == 'B' && i + 1 < len && s[i + 1] == 'G') {
            swap(s, i);
            i++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int size, t;
    string s;
    cin >> size >> t >> s;
    for (int i = 0; i < t; i++) {
        util(s, size);
    }
    cout << s << endl;
    return 0;
}
