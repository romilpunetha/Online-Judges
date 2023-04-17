#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int mod = 1000000007;

long long int nonfib(long long int n) {
    long long int a = 1, b = 1, c = 2;
    while (n > 0) {
        a = b;
        b = c;
        c = a + b;
        n -= (c - b - 1);
    }
    n += (c - b - 1);
    long long ans = b + n;
    return ans;
}

vector<vector<long long int> > mul(vector<vector<long long int> >& a, vector<vector<long long int> >& b) {
    vector<vector<long long int> > res(2, vector<long long int>(2, 1));
    res[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
    res[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
    res[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
    res[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {
            res[i][j] = res[i][j] % mod;
        }
    }
    return res;
}

vector<vector<long long int> > fastexp(vector<vector<long long int> > arr, int q) {
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

long long int fastexp(long long int A, long long int B) {
    if (B == 0)
        return 1;
    long long int res = 1;
    while (B) {
        if (B & 1) {
            res = ((res % mod) * (A % mod)) % mod;
        }
        A = ((A % mod) * (A % mod)) % mod;
        B >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int A, B, test;
    cin >> test;
    vector<vector<long long int> > arr(2, vector<long long int>(2, 0));
    arr[0][0] = 1;
    arr[0][1] = 1;
    arr[1][0] = 1;
    arr[1][1] = 0;
    while (test--) {
        cin >> A;
        if (A == 1)
            B = 1;
        else if (A == 2)
            B = 1;
        else if (A == 3)
            B = 2;
        else {
            vector<vector<long long int> > res = fastexp(arr, A - 3);
            B = res[0][0] + res[0][1];
        }
        A = nonfib(A);
        B = B % mod;
        long long ans = fastexp(A, B);
        cout << ans << endl;
    }
    return 0;
}
