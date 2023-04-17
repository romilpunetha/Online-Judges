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

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int arr[n][32];
    V<int> inp(n);
    memset(arr, 0, sizeof(arr));
    MP<int, int> st;
    for (int i = 0; i < n; i++) cin >> inp[i];
    sort(all(inp));
    for (int i = 0; i < n; i++) st[inp[i]] = i;
    for (auto &it : st) {
        for (int i = 0; i < 32; i++) {
            int k = it.ff + (1 << i);
            st.find(k) != st.end() ? arr[st[k]][i] = max(arr[st[k]][i], arr[st[it.ff]][i] + 1) : 0;
        }
    }
    int a = 0, b = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 32; j++) {
            if (arr[i][j] > ans) ans = arr[i][j], a = i, b = j;
        }
    }
    ans++;
    cout << min(ans, 3) << endl;
    for (int i = 0; i < min(ans, 3); i++) {
        cout << inp[a] - (i * (1 << b)) << " ";
    }
    return 0;
}
