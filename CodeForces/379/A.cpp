#include <bits/stdc++.h>
#define tr1(x) cerr << #x << ":\t" << x << endl
#define tr2(x, y) cerr << #x << ":\t" << x << "\t|\t" << #y << ":\t" << y << endl
#define tr3(x, y, z) cerr << #x << ":\t" << x << "\t|\t" << #y << ":\t" << y << "\t|\t" << #z << ":\t" << z << endl
#define tr4(a, b, c, d) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << endl
#define tr5(a, b, c, d, e) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << "\t|\t" << #e << ":\t" << e << endl
#define tr6(a, b, c, d, e, f) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << "\t|\t" << #e << ":\t" << e << "\t|\t" << #f << ":\t" << f << endl
#define base 999983
#define baseinv 943912055
#define ff first
#define ss second
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) a += s[i] == 'A', b += s[i] == 'D';
    if (a > b)
        cout << "Anton\n";
    else if (a < b)
        cout << "Danik\n";
    else
        cout << "Friendship\n";
    return 0;
}
