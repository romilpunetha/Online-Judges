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

string a, b;
int l;

bool can_1(char m, char n, char o, char p) {
    return (m == '0') && (o == '0') && (p == '0');
}

bool can_2(char m, char n, char o, char p) {
    return (m == '0') && (n == '0') && (o == '0');
}

bool can_3(char m, char n, char o, char p) {
    return (m == '0') && (n == '0') && (p == '0');
}

bool can_4(char m, char n, char o, char p) {
    return (n == '0') && (o == '0') && (p == '0');
}

void fit(int i, char m, char n, char o, char p) {
    a[i] = m, a[i + 1] = n, b[i] = 0, b[i + 1] = p;
}

int check() {
    int ans = 0;
    for (int i = 0; i + 1 < l; i++) {
        if (can_1(a[i], a[i + 1], b[i], b[i + 1])) fit(i, 'X', a[i + 1], 'X', 'X'), ans++;
        if (can_2(a[i], a[i + 1], b[i], b[i + 1])) fit(i, 'X', 'X', 'X', b[i + 1]), ans++;
        if (can_3(a[i], a[i + 1], b[i], b[i + 1])) fit(i, 'X', 'X', b[i], 'X'), ans++;
        if (can_4(a[i], a[i + 1], b[i], b[i + 1])) fit(i, a[i], 'X', 'X', 'X'), ans++;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> a >> b;
    l = a.length();
    cout << check();
    return 0;
}
