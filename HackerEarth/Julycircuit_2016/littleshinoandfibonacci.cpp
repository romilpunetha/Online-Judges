#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
ll test, l, r, mod = 1e9 + 7;

vector<vector<long long int> > mul(vector<vector<long long int> >& a, vector<vector<long long int> >& b) {
    vector<vector<long long int> > res(2, vector<long long int>(2, 1));
    res[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
    res[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
    res[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
    res[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {
            res[i][j] %= 100000000000;
        }
    }
    return res;
}

vector<vector<long long int> > fastexp(vector<vector<long long int> > arr, ll q) {
    vector<vector<long long int> > res(2, vector<long long int>(2, 1));
    if (q == 0)
        return arr;
    while (q) {
        if (q & 1) {
            res = mul(res, arr);
        }
        arr = mul(arr, arr);
        q >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    scanf(" %lld", &test);
    while (test--) {
        scanf(" %lld %lld", &l, &r);
        vector<vector<long long int> > arr(2, vector<long long int>(2, 0));
        arr[0][0] = 1;
        arr[0][1] = 1;
        arr[1][0] = 1;
        arr[1][1] = 0;
        l += 1;
        r += 2;
        if (l == 3 || l == 2) l = 1;
        if (r == 3 || r == 2) r = 1;
        if (l > 3) {
            vector<vector<long long int> > res = fastexp(arr, l - 3);
            l = res[0][0];
        }
        if (r > 3) {
            vector<vector<long long int> > res = fastexp(arr, r - 3);
            r = res[0][0];
        }
        r %= mod;
        l %= mod;
        printf("%lld\n", (r - l + mod) % mod);
    }
    return 0;
}
