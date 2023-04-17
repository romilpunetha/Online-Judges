/* ________________________________
 /\                               \
 \_| Bismillah-ir-Rahman-ir-Rahim |
   |   ___________________________|_
   \_/_____________________________/
   */
#include <iostream>
// #include <ostream> //for flush, but no need
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <ctime>
#include <fstream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
// #include <cassert>
using namespace std;
#define PI acos(-1.0)
#define p(x) cerr << x << endl
#define sz(a) int((a).size())
#define all(a) a.begin(), a.end()
#define set0(ar) memset(ar, 0, sizeof ar)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define START_RED "\033[1;31m"
#define END_RED "\033[0m"
#define nl cerr << endl;
#include <chrono>
#include <thread>
// cout << fixed << setprecision(20) << p << endl;
// string s(10, '*'); // string with 10 star characters
// getline(cin, name);
// assert(n!=0 && "n can't be zero");
typedef long long ll;
ll mod = 1e9 + 7;

#ifdef CODING
template <typename I>
void _DOING(const char *s, I &&x) { cerr << s << "=" << x << endl; }   // without ','
template <typename I, typename... T>
void _DOING(const char *s, I &&x, T &&...tail) {   // with ','
    int c = 0;
    static const char bra[] = "({[", ket[] = ")}]";
    while (*s != ',' || c != 0) {   // eg. mkp(a,b)
        if (strchr(bra, *s)) c++;
        if (strchr(ket, *s)) c--;
        cerr << *s++;
    }
    cerr << "=" << x << ", ";
    _DOING(s + 1, tail...);
}
//    fprintf(stderr,"%s:%d - ",__PRETTY_FUNCTION__,__LINE__);
#define debug(...)                         \
    do {                                   \
        _DOING(#__VA_ARGS__, __VA_ARGS__); \
    } while (0);

template <typename It>
ostream &_OUTC(ostream &s, It b, It e, string st, string end) {
    s << st;
    for (auto it = b; it != e; it++) s << (it == b ? "" : " ") << *it;
    s << end;
    return s;
}
template <typename A, typename B>
ostream &operator<<(ostream &s, const pair<A, B> &p) { return s << "(" << p.first << "," << p.second << ")"; }
template <typename A, typename B>
ostream &operator<<(ostream &s, const map<A, B> &c) { return _OUTC(s, all(c), "{{ ", " }}"); }
template <typename T>
ostream &operator<<(ostream &s, const set<T> &c) { return _OUTC(s, all(c), "{ ", " }"); }
template <typename T>
ostream &operator<<(ostream &s, const vector<T> &c) { return _OUTC(s, all(c), "[", "]"); }
#else
#define debug(...)
#endif

int isPrime(ll x) {
    ll s = sqrt(x);
    int i;
    if (x <= 1) return 0;
    if (x == 2 || x == 3) return 1;
    if (x % 2 == 0 || x % 3 == 0) return 0;
    for (i = 5; i <= s; i += 6)
        if (x % i == 0 || x % (i + 2) == 0) return 0;
    return 1;
}
vector<string> &split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim))
        if (!item.empty()) elems.push_back(item);
    return elems;
}

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

inline void __fio() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
}   // fastio

template <class T>
inline T bigmod(T p, T e, T M) {
    ll ret = 1;
    for (; e > 0; e >>= 1) {
        if (e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T>
inline T gcd(T a, T b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
template <class T>
inline T modinverse(T a, T M) { return bigmod(a, M - 2, M); }

/*
Avaiable functions:
string
    split(string, delim, vector of elems output)
stl
    cout vectorObj, mapObj, setObj
    sz(container);
vector:
    mp, pb, fi and se for vector

Logging:
    p( string message only );
    debug( var1, var2, vec);

math:
    gcd(T, T)
    bigmod(a, n, mod)
    modinverse(a, mod) // mod should be prime here
 */
// template ends

int main(int argc, char *argv[]) {   //__fio();
    ll tt;
    cin >> tt;
    for (int qq = 1; qq <= tt; qq++) {
        ll n = 0, ans = 0;
        int _time0 = clock();
        ll i, j;
        string s;
        cin >> s >> i >> j;

        n = s.size();
        int cb = 0, cr = 0;
        for (int ii = 0; ii < n; ii++)
            if (s[ii] == 'B')
                cb++;
            else
                cr++;

        i--;
        j--;
        ll blocki = i / n;
        ll blockj = j / n;

        if (blocki == blockj) {
            i = i % n;
            j = j % n;
            for (int k = i; k <= j; k++)
                ans += (s[k] == 'B');

        } else {
            ll total = (blockj - blocki - 1) * cb;
            ans += total;
            i = i % n;
            for (int k = i; k <= n - 1; k++)
                ans += (s[k] == 'B');

            j = j % n;
            for (int k = 0; k <= j; k++)
                ans += (s[k] == 'B');
        }

        cout << "Case #" << qq << ": " << ans << endl;

        cout << flush;
        // cerr<<START_RED << "test "<<qq<<" solved in "<<int(clock() - _time0)<<"us"<<END_RED<<"\n";
    }
    // cerr<<START_RED<<"time: "<< double(clock() - _time)/double(CLOCKS_PER_SEC)*1000<<"ms"<<END_RED<<endl;
    return 0;
}
