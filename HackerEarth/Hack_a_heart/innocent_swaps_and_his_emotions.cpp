#include<bits/stdc++.h>
#define endl '\n'
#define inf INT_MAX
#define pb push_back
#define present(c,x) ((c).find(x) != (c).end())
#define mod 1000000007
#define base 999983
#define baseinv 943912055
#define ff first
#define ss second
#define tr1(x)                cerr << #x << ": " << x << endl;
#define tr2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define tr3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define tr4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define tr5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define tr6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#define all(a) (a).begin(),(a).end()
using namespace std;
typedef long long ll;

vector<ll> fact(1e6 + 10, 1);

ll expo(ll a, ll b){
    ll res = 1;
    while(b){
        if(b & 1) res *= a;
        a *= a;
        b >>= 1;
        a %= mod;
        res %= mod;
    }
    return res;
}

ll invmod(ll a){
    return expo(a % mod, mod - 2);
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    for(int i = 1; i < 1e6 + 10; i++) fact[i] = (i * fact[i - 1]) % mod;
    int n; cin >> n; while(n--){
        ll a, b; cin >> a >> b;
        a = ( fact[a] * invmod(fact[b] * fact[a - b]) ) % mod;
        b = expo(2, b);
        a = (( a * b ) % mod + mod ) % mod;
        cout << a << endl;
    }
    return 0;
}

