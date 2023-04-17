#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, s1 = 0, s2 = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        s1 |= a;
    }
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        s2 |= b;
    }
    cout << s1 + s2 << endl;
    return 0;
}
