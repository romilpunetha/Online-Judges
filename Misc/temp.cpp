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

vector<pair<int, int> > arr;

bool is_prime(int x) {
    for (int i = 2; i < x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

void util(int x) {
    for (int i = 2; x > 1; i++) {
        int cnt = 0;
        if (is_prime(i)) {
            while (x % i == 0) {
                x /= i;
                cnt++;
            }
            arr.pb({ i, cnt });
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int x;
    cin >> x;
    x++;
    util(x);
    cout << arr.size() << endl;
    cout << "[ ";
    for (auto &it : arr) cout << it.ss << ", ";
    cout << "]";
    return 0;
}
