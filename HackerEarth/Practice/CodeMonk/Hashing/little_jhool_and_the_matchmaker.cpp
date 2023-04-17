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

unordered_set<char> st = { 'l', 'i', 't', 'e', 'j', 'h', 'o' };

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int test;
    cin >> test;
    cin.ignore(inf, '\n');
    string s;
    while (test--) {
        int n, k;
        cin >> n >> k;
        string s;
        map<pair<int, int>, string> mp;
        for (int j = 0; j < n; j++) {
            cin >> s;
            int cnt = 0, i = 0;
            unordered_set<char> st2;
            while (s[i]) {
                st2.insert(tolower(s[i++]));
            }
            for (auto &it : st2) {
                if (present(st, it)) cnt++;
            }
            mp[{ cnt, j }] = s;
        }
        int t = 0;
        for (auto &it : mp) {
            cout << it.ss << " ";
            t++;
            if (t == k) break;
        }
        cout << endl;
    }
    return 0;
}
