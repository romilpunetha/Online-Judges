#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int n, m, k, x = 1, y = 1, dir = 1, tot;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    tot = n * m;
    while ((k--) > 1) {
        cout << 2 << " ";
        cout << x << " " << y << " ";
        y += dir;
        if (y > m || y == 0) x++, dir = -dir, y += dir;
        cout << x << " " << y << endl;
        y += dir;
        if (y > m || y == 0) x++, dir = -dir, y += dir;
        tot -= 2;
    }
    cout << tot << " ";
    while (tot--) {
        cout << x << " " << y << " ";
        y += dir;
        if (y > m || y == 0) x++, dir = -dir, y += dir;
    }
    cout << endl;
    return 0;
}
