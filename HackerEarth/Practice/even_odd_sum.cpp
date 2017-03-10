#include<bits/stdc++.h>
#define endl '\n'
#define inf INT_MAX
#define pb push_back
#define der(c, x) ((c).find(x) != (c).end())
#define base 999983
#define baseinv 943912055
#define mod 1000000007
#define ff first
#define ss second
#define V vector
#define L list
#define P pair
#define M map
#define S set
#define UM unordered_map
#define MM multimap
#define UMM unordered_multimap
#define MS multiset
#define US unordered_set
#define UMS unordered_multiset
#define PQ priority_queue
#define Graph list<int>*
#define tr1(x)                cerr << #x << ": " << x << endl;
#define tr2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define tr3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define tr4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define tr5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define tr6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#define all(a) (a).begin(),(a).end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ldbl;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n, el = 0, ol = 0; cin >> n;
    V<ll> elc(n + 2, 0), erc, olc, orc, arr;
    erc = olc = orc = arr =  elc;
    for(int i = 1; i <= n; i++){
        int t; cin >> t; arr[i] = t;
        if(t & 1){
            olc[i] = olc[i - 1] + ol + 1;
            ol++;
            el = 0;
        }
        else{
            elc[i] = elc[i - 1] + el + 1;
            el++;
            ol = 0;
        }
    }
    el = ol = 0;
    for(int i = n; i >= 1; i--){
        int t; t = arr[i];
        if(t & 1){
            orc[i] = orc[i + 1] + ol + 1;
            ol++;
            el = 0;
        }
        else{
            erc[i] = erc[i + 1] + el + 1;
            el++;
            ol = 0;
        }
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans += elc[i] * erc[i + 1] + olc[i] * orc[i + 1];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}

