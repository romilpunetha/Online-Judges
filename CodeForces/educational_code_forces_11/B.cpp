#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int t = m - 2 * n, i = 0;
    while (m) {
        if (t > 0) {
            cout << 2 * n + 2 * i + 1 << " ";
            t--;
            m--;
        }
        if (m) {
            cout << 2 * i + 1 << " ";
            m--;
        }
        if (t > 0) {
            cout << 2 * n + 2 * i + 2 << " ";
            t--;
            m--;
        }
        if (m) {
            cout << 2 * i + 2 << " ";
            m--;
        }
        i++;
    }
    return 0;
}
