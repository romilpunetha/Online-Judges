#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
#define PI 3.14159265
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int test;
    cin >> test;
    while (test--) {
        long double s, v;
        cin >> s >> v;
        cout << fixed << setprecision(20) << (2.0 * s) / (3 * v) << endl;
    }
    return 0;
}
