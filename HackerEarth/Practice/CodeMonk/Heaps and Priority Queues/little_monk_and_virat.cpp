#include <bits/stdc++.h>
#define endl '\n'
#define inf INT_MAX
#define pb push_back
#define present(c, x) ((c).find(x) != (c).end())
#define mod 1000000007
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
    int n, q;
    cin >> n;
    vector<ll> arr(n, 0), brr(n, 1);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            ll t;
            cin >> t;
            arr[j] += t;
        }
    }
    sort(all(arr));
    multiset<ll> st(all(arr));
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t > st.size())
            cout << -1 << endl;
        else {
            for (auto &it : st) {
                t--;
                if (t == 0) {
                    cout << it << endl;
                    st.erase(st.find(it));
                    break;
                }
            }
        }
    }
    return 0;
}
