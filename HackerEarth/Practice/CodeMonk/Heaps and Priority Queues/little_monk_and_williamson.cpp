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
    map<int, int> mp;
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        if (s == "Push") {
            int t;
            cin >> t;
            mp[t]++;
        } else if (s == "Diff") {
            if (mp.empty()) {
                cout << -1 << endl;
                continue;
            }
            cout << mp.rbegin()->ff - mp.begin()->ff << endl;
            mp.rbegin()->ss--;
            if (mp.rbegin()->ss == 0) mp.erase(mp.rbegin()->ff);
            if (!mp.empty()) mp.begin()->ss--;
            if (!mp.empty() && mp.begin()->ss == 0) mp.erase(mp.begin()->ff);
        } else if (s == "CountHigh") {
            if (mp.empty())
                cout << -1 << endl;
            else
                cout << mp.rbegin()->ss << endl;
        } else {
            if (mp.empty())
                cout << -1 << endl;
            else
                cout << mp.begin()->ss << endl;
        }
    }
    return 0;
}
