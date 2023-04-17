
// {{{
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
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define FOR(i, x, y) for (long long int i = (x); i <= (y); ++i)
#define ROF(i, x, y) for (long long int i = (y); i >= (x); --i)
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define all(x) (x).begin(), (x).end()
#define lcm(x, y) (((x) / gcd((x), (y))) * (y))
#define abs(x) ((x) < 0 ? -(x) : (x))
#define sq(x) ((x) * (x))
// }}}
// {{{
/*************************************************************************************************/
/*************************************************************************************************/
/****************************************TEMPLATE STARTS HERE*************************************/
/*************************************************************************************************/
/*************************************************************************************************/
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, int> psi;
typedef pair<int, string> pis;
typedef vector<pii> vii;
typedef vector<int> vi;
const ll inf = 2147383647;
// }}}
// {{{
template <class T>
void display(vector<vector<T> >& arr) {
    typename vector<vector<T> >::iterator ii;
    typename vector<T>::iterator ij;
    cout << "Vector contains:" << endl;
    for (ii = arr.begin(); ii != arr.end(); ii++) {
        for (ij = (*ii).begin(); ij != (*ii).end(); ij++) {
            cout << *ij << " ";
        }
        cout << endl;
    }
    cout << endl;
}
template <class T>
void display(vector<T>& arr) {
    typename vector<T>::iterator it;
    cout << "Vector contains:" << endl;
    for (it = arr.begin(); it != arr.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
template <typename T>
void swaps(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}
template <typename T1, typename T2>
T1 power(T1 num, T2 a) {
    if (a == 0) {
        return 1;
    }
    double res = 0;
    while (a) {
        if (a & 1) {
            res = res * num;
        }
        num = num * num;
        a >>= 1;
    }
    return (T1)res;
}
template <typename T1, typename T2, typename T3>
T3 bigmod(T1 num, T2 a, T3& mod) {
    if (mod == 1) {
        return 0;
    }
    ll res = 0;
    while (a) {
        if (a & 1) {
            res = (res * num) % mod;
        }
        num = (num * num) % mod;
        a >>= 1;
    }
    return res;
}
template <typename T1, typename T2, typename T3, typename T4>
T2 inverse(T1 a, T2 b, T3& X, T4& Y) {
    T3 x = 1;
    T4 y = 0;
    X = 0;
    Y = 1;
    ll q, r, m, n;
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
template <typename T1, typename T2>
T1 modinv(T1 a, T2 b) {
    ll x = 0, y = 0;
    inverse(a, b, x, y);
    x = x < 0 ? x + b : x;
    return (T1)x;
}
template <typename T>
T gcd(T a, T b) {
    if (b == 0) {
        return a;
    }
    T x = 0, y = 0;
    T res = inverse(a, b, x, y);
    return res;
}
/*************************************************************************************************/
/*************************************************************************************************/
/****************************************TEMPLATE ENDS HERE***************************************/
/*************************************************************************************************/
/*************************************************************************************************/
// }}}

int fib(int col) {
    if (col == 0) {
        return 1;
    }
    int a = 1, b = 1, c;
    FOR(i, 1, col) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main() {
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--) {
        int col;
        cin >> col;
        int res = fib(col);
        cout << sq(res) << endl;
    }
    return 0;
}
