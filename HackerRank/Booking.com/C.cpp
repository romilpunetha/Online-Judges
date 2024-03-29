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
#define Graph list<int> *
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

V<ll> parse(string &s, char delim) {
    s += delim;
    int prev = 0, curr = 0;
    while ((curr = s.find(delim, prev)) != string::npos) {
        string subst = s.substr(prev, curr - prev);
        prev = curr + 1;
        arr.pb(stoi(subst));
    }
    return arr;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    string t;
    cin >> t;
    V<ll> arr = parse(t, ' ');
    int len = arr.size();
    cout << arr[0] << " ";
    for (int i = 1; i < len; i++) {
        ll diff = arr[i] - arr[i - 1];
        if (diff < -127 || diff > 127) cout << -128 << " ";
        cout << diff << " ";
    }
    return 0;
}
