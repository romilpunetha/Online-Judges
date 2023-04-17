#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string s;
    int i = 1;
    while (s.size() < n) {
        s += to_string(i);
        i++;
    }
    cout << s[n - 1] << endl;
    return 0;
}
