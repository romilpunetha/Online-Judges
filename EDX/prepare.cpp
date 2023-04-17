#include <bits/stdc++.h>
#define tr1(x) cerr << #x << ":\t" << x << endl
#define tr2(x, y) cerr << #x << ":\t" << x << "\t|\t" << #y << ":\t" << y << endl
#define tr3(x, y, z) cerr << #x << ":\t" << x << "\t|\t" << #y << ":\t" << y << "\t|\t" << #z << ":\t" << z << endl
#define tr4(a, b, c, d) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << endl
#define tr5(a, b, c, d, e) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << "\t|\t" << #e << ":\t" << e << endl
#define tr6(a, b, c, d, e, f) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << "\t|\t" << #e << ":\t" << e << "\t|\t" << #f << ":\t" << f << endl
#define ff first
#define ss second
using namespace std;
typedef long long ll;

bool C(const pair<int, int>& a, const pair<int, int>& b) {
    return a.ff - a.ss < b.ff - b.ss;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    freopen("prepare.in", "r", stdin);
    freopen("prepare.out", "w", stdout);
    int n, f1 = 0, f2 = 0;
    cin >> n;
    vector<pair<int, int> > arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i].ff;
    for (int i = 0; i < n; i++) cin >> arr[i].ss;
    sort(arr.begin(), arr.end(), C);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].ff >= arr[i].ss)
            ans += arr[i].ff, f1 = 1;
        else
            ans += arr[i].ss, f2 = 1;
    }
    if (f1 && f2) return cout << ans << endl, 0;
    if (f1)
        ans += -arr[0].ff + arr[0].ss;
    else
        ans += -arr[n - 1].ss + arr[n - 1].ff;
    cout << ans << endl;
    return 0;
}
