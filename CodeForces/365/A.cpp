#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int n, a, b;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    while (n--) {
        int p, q;
        cin >> p >> q;
        a += p > q;
        b += q > p;
    }
    cout << ((a > b) ? "Mishka" : ((a == b ? "Friendship is magic!^^" : "Chris"))) << endl;
    return 0;
}
