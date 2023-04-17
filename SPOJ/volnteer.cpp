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

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    for (auto &it : arr) cin >> it;
    sort(arr.begin(), arr.end());
    ll ans = 0, a = arr.size() - 1, b = 0;
    while (k && a > b && arr[a - 1] >= 0 && arr[b + 1] < 0) {
        if (k > 1 && abs(arr[b] + arr[b + 1]) >= arr[a] + arr[a - 1])
            ans += abs(arr[b] + arr[b + 1]), k--, b += 2;
        else
            ans += arr[a--];
        k--;
    }
    if (k) {
        if (k == 1)
            ans = (ans + abs(arr[a])) * (arr[a] < 0 ? -1 : 1), k--;
        else if (arr[b + 1] >= 0)
            while (k)
                ans += arr[a--], k--;
        else if (arr[a - 1] < 0)
            while (k > 1)
                ans = (ans + abs(arr[b]) + abs(arr[b + 1])) * (arr[b] * arr[b + 1] < 0 ? -1 : 1), b += 2, k -= 2;
        while (k)
            ans = (ans + abs(arr[a])) * (arr[a] < 0 ? -1 : 1), k--, a--;
    }
    cout << ans << endl;
    return 0;
}
