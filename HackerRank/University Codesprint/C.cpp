#include <bits/stdc++.h>
#define tr1(x) cerr << #x << ":\t" << x << endl
#define tr2(x, y) cerr << #x << ":\t" << x << "\t|\t" << #y << ":\t" << y << endl
#define tr3(x, y, z) cerr << #x << ":\t" << x << "\t|\t" << #y << ":\t" << y << "\t|\t" << #z << ":\t" << z << endl
#define tr4(a, b, c, d) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << endl
#define tr5(a, b, c, d, e) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << "\t|\t" << #e << ":\t" << e << endl
#define tr6(a, b, c, d, e, f) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << "\t|\t" << #e << ":\t" << e << "\t|\t" << #f << ":\t" << f << endl
#define base 999983
#define baseinv 943912055
#define ff first
#define ss second
using namespace std;
typedef long long ll;

int n;
vector<int> bit(1e6, 0);

void update(int i, int val) {
    while (i < 1e6) {
        bit[i] += val;
        i += i & -i;
    }
}

int query(int i) {
    int res = 0;
    while (i) {
        res += bit[i];
        i -= i & -i;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = n + 1; i <= n + n; i++) {
        int t;
        cin >> t;
        if (t >= n) continue;
        update(i - n + 1, 1);
        update(i - t + 1, -1);
    }
    int mx = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        int p = query(i) + query(i + n);
        if (p > mx) mx = p, ans = i;
    }
    cout << ans << endl;
    return 0;
}
