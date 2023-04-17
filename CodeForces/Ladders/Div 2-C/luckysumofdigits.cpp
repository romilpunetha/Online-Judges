#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int i = n / 7;
    while (i >= 0) {
        if ((n - (7 * i)) % 4 == 0) {
            for (int j = 0; j < (n - (7 * i)) / 4; j++) cout << 4;
            for (int j = 0; j < i; j++) cout << 7;
            return 0;
        }
        i--;
    }
    cout << -1 << endl;
    return 0;
}
