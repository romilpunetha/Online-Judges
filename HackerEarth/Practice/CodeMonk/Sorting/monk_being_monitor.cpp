#include <bits/stdc++.h>
#define endl '\n'
#define inf INT_MAX
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

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int test;
    cin >> test;
    while (test--) {
        int ans = -1, n;
        cin >> n;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            mp[t]++;
        }
        vector<pair<int, int>> arr(mp.size());
        int j = 0;
        for (auto &it : mp) arr[j++] = { it.ff, it.ss };
        sort(arr.begin(), arr.end());
        int mx = arr[j - 1].ss;
        for (int i = j - 1; i >= 0; i--) {
            if (arr[i].ss > mx)
                mx = arr[i].ss;
            else
                ans = max(ans, mx - arr[i].ss);
        }
        cout << (ans == 0 ? -1 : ans) << endl;
    }
    return 0;
}
