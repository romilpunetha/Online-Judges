#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    for (cin >> test; test--;) {
        int n, a = -1, b = -1, c = -1, flag = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            a = b;
            b = c;
            cin >> c;
            if (i >= 2 && !flag) flag = (a == b) && (b == c);
        }
        cout << (flag ? "Yes" : "No") << endl;
    }
    return 0;
}
