#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double dist(double a, double b, double p, double q) {
    return sqrt(pow(a - p, 2) + pow(b - q, 2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double r, x, y, a, b;
    cin >> r >> x >> y >> a >> b;
    if (x == a && y == b) {
        cout << 0 << endl;
        return 0;
    }
    int cnt = 0;
    ;
    double lim = dist(a, b, x, y);
    while (lim > 2 * r) {
        lim -= 2 * r;
        cnt++;
    }
    cout << cnt + 1 << endl;
    return 0;
}
