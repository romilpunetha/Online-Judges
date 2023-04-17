#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#define ull unsigned long long
#define ll long long
#define sci(i) scanf("%d", &i)
#define scl(i) scanf("%ld", &i)
#define scll(i) scanf("%lld", &i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define loop(i, x, y) for (int i = x; i < y; ++i)

using namespace std;

typedef pair<int, int> pii;
typedef map<int, int> mii;
typedef map<int, int>::iterator miit;
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }
ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); }
int main() {
    ull n, k;
    while (true) {
        scll(n);
        scll(k);
        if (n == -1 && k == -1)
            break;
        else if (k <= 2)
            cout << 0 << endl;
        else {
            ll nn = (k - 1) / 2;
            ll p = nn * k - nn * (nn + 1);
            // cout << p << endl;
            ll q;
            if (n & 1)
                q = ((n - 1) / 2) * n;
            else
                q = (n / 2) * (n - 1);
            // cout << p << " "  << q << endl;
            while (true) {
                ll g = gcd(p, q);
                if (g == 1) break;
                // cout <<"gcd:"<< g << endl;
                p /= g;
                q /= g;
                if (p == 1 || q == 1) break;
            }
            if (q == 1) printf("%lld\n", p);
            printf("%lld/%lld\n", p, q);
        }
    }
    // system("pause");
    return 0;
}
