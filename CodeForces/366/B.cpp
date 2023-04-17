#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x = 0;
    cin >> n;
    while (n--) {
        int t;
        cin >> t;
        x += t - 1;
        cout << (x & 1 ? "1" : "2") << endl;
    }
    return 0;
}
