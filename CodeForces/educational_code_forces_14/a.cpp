#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, c = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        c += (t == 0);
    }
    if ((n == 1 && c != 0) || (n > 1 && c != 1))
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    return 0;
}
