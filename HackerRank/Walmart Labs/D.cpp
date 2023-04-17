#include <bits/stdc++.h>
#define tr1(x) cerr << #x << ":\t" << x << endl
#define tr2(x, y) cerr << #x << ":\t" << x << "\t|\t" << #y << ":\t" << y << endl
#define tr3(x, y, z) cerr << #x << ":\t" << x << "\t|\t" << #y << ":\t" << y << "\t|\t" << #z << ":\t" << z << endl
#define tr4(a, b, c, d) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << endl
#define tr5(a, b, c, d, e) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << "\t|\t" << #e << ":\t" << e << endl
#define tr6(a, b, c, d, e, f) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << "\t|\t" << #e << ":\t" << e << "\t|\t" << #f << ":\t" << f << endl
#define ff first
#define ss second
using namespace std;
typedef long long ll;
int mod = 1e9 + 7;
vector<ll> catalan(4010, 0);

void ini() {
    catalan[1] = 1;
    for (int i = 2; i <= 4000; i++) {
        for (int j = 1; j <= i - 1; j++) {
            catalan[i] = (catalan[i] + ((catalan[j]) * catalan[i - j]) % mod) % mod;
        }
        catalan[i] = catalan[i] % mod;
    }
    for (int i = 1; i <= 4000; i++) {
        catalan[i] += catalan[i - 1];
        catalan[i] %= mod;
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ini();
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        cout << catalan[n / 2 + 1] - 1 << endl;
    }
    return 0;
}
