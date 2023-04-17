#include <limits.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

long long int euclid(long long int a, long long int b, long long int &X, long long int &Y) {
    long long int x = 1, y = 0;
    X = 0;
    Y = 1;
    long long int q, r, m, n;
    while (a != 0) {
        q = b / a;
        r = b % a;
        m = X - q * x;
        n = Y - q * y;
        X = x;
        Y = y;
        x = m;
        y = n;
        b = a;
        a = r;
    }
    return b;
}

long long int modinv(long long int a, long long int b) {
    long long x = 0, y = 0;
    euclid(a, b, x, y);
    x = x < 0 ? x + b : x;
    return x;
}
int main() {
    ios_base::sync_with_stdio(false);
    long long int mod = 1000000009;
    int test;
    cin >> test;
    while (test--) {
        long long int n, k, c, res, sum;
        cin >> n >> k >> c;
        if (n == 1) {
            cout << "0\n";
            continue;
        }
        n %= mod;
        k %= mod;
        c %= mod;
        res = ((((n - 1) * n) % mod) * (n + 1)) % mod;
        res = res < 0 ? res + mod : res;
        // res=(res*modinv(6,mod))%mod;
        res = res / 6;
        res *= k;
        sum = ((n - 1) * n) % mod;
        sum = sum < 0 ? sum + mod : sum;
        sum = (sum * c) % mod;
        // sum=(sum*modinv(2,mod))%mod;
        sum = sum / 2;
        res = (res + sum) % mod;
        cout << res << endl;
    }
    return 0;
}
