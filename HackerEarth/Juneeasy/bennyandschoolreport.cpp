#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    while (test--) {
        ll avg, n, sum = 0, M;
        cin >> n >> M >> avg;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            sum += temp;
        }
        ll res = (avg * (n + 1)) - sum;
        cout << (res > M ? "Impossible" : (res <= 0) ? "1"
                                                     : to_string(res))
             << endl;
    }
    return 0;
}
