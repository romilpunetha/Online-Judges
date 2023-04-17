#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, p, t;
    cin >> n;
    if (n == 1) {
        int t;
        cin >> t;
        if (t == 0) return cout << "UP\n", 0;
        if (t == 15)
            return cout << "DOWN\n", 0;
        else
            cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        p = t;
        cin >> t;
    }
    if (t == 0 || (t != 15 && t > p))
        cout << "UP\n";
    else
        cout << "DOWN\n";
    return 0;
}
