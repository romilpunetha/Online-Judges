#include <bits/stdc++.h>
#define endl '\n'
#define inf int_max
#define pb push_back
#define present(c, x) ((c).find(x) != (c).end())
#define base 999983
#define baseinv 943912055
#define ff first
#define ss second
#define tr1(x) cerr << #x << ": " << x << endl;
#define tr2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define tr3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define tr4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define tr5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define tr6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int n;
int a[4];
vector<vector<int> > arr;
bool flag = 0;

void util(int st, int p = 0, int q = 0, int r = 0, int s = 0) {
    if (a[0] == p && a[1] == q && a[2] == r && a[3] == s) {
        flag = 1;
        return;
    }
    if (st >= n) return;
    util(st + 1, p + arr[st][0], q + arr[st][1], r + arr[st][2], s + arr[st][3]);
    util(st + 1, p, q, r, s);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    cin >> n;
    arr.resize(n);
    for (auto &it : arr) it.resize(4);
    for (auto &it : arr) {
        for (auto &jt : it) cin >> jt;
    }
    util(0);
    if (flag)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
