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
#define MS multiset
#define US unordered_set
#define UMS unordered_multiset
#define PQ priority_queue
#define Graph list<int>*
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

int n;
V<ll> arr(1e5), dp_cnt(1e5, 0), dp_sum(1e5, 0);

ll ans_cnt = INT_MIN, ans_sum = INT_MIN;

void solve() {
    for (int i = 0; i < n; i++) dp_cnt[i] = 1, dp_sum[i] = abs(arr[i]);
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] * arr[i] < 0 && abs(arr[i]) > abs(arr[j])) {
                if (dp_cnt[i] < dp_cnt[j] + 1) dp_cnt[i] = dp_cnt[j] + 1;
                if (dp_sum[i] < dp_sum[j] + abs(arr[i])) dp_sum[i] = dp_sum[j] + abs(arr[i]);
            }
        }
    }
    for (int i = 0; i < n; i++) ans_cnt = max(ans_cnt, dp_cnt[i]), ans_sum = max(ans_sum, dp_sum[i]);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    solve();
    cout << ans_cnt << " " << ans_sum << endl;
    return 0;
}
