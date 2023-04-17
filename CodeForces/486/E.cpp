#include <bits/stdc++.h>
#define endl '\n'
#define inf INT_MAX
#define pb push_back
#define der(c, x) ((c).find(x) != (c).end())
#define base 999983
#define baseinv 943912055
#define ff first
#define ss second
#define V vector
#define L list
#define P pair
#define MP map
#define ST set
#define UM unordered_map
#define MM multimap
#define UMM unordered_multimap
#define MST multiset
#define UST unordered_set
#define UMS unordered_multiset
#define PQ priority_queue
#define Graph V<L<int> >
#define tr1(x) cerr << #x << ": " << x << endl;
#define tr2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define tr3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define tr4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define tr5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define tr6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ldbl;

int util(int a, int b, V<int> arr) {
    int l = arr.size();
    int ans = 0;
    int j = l - 1, i = l - 2;
    while (j >= 0 && arr[j] != b) j--;
    if (j < 0) return INT_MAX;
    while (j + 1 < l) swap(arr[j], arr[j + 1]), ans++, j++;
    while (i >= 0 && arr[i] != a) i--;
    if (i < 0) return INT_MAX;
    while (i + 1 < l - 1) swap(arr[i], arr[i + 1]), ans++, i++;
    int k = 0;
    if (arr[k] == 0) {
        while (arr[k] == 0) k++;
        if (k == l - 2 || k == l - 1) return INT_MAX;
        while (k - 1 >= 0) swap(arr[k], arr[k - 1]), ans++, k--;
    }
    return ans;
}

void solve(ll n) {
    V<int> arr;
    while (n) {
        arr.pb(n % 10);
        n /= 10;
    }
    reverse(all(arr));
    int cnt = INT_MAX;
    cnt = min(cnt, util(0, 0, arr));
    cnt = min(cnt, util(2, 5, arr));
    cnt = min(cnt, util(5, 0, arr));
    cnt = min(cnt, util(7, 5, arr));
    if (cnt == INT_MAX)
        cout << "-1" << endl;
    else
        cout << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n;
    cin >> n;
    solve(n);
    return 0;
}
