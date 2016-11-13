#include<bits/stdc++.h>
#define tr1(x)                cerr << #x << ":\t" << x << endl
#define tr2(x, y)             cerr << #x << ":\t" << x << "\t|\t" << #y << ":\t" << y << endl
#define tr3(x, y, z)          cerr << #x << ":\t" << x << "\t|\t" << #y << ":\t" << y << "\t|\t" << #z << ":\t" << z << endl
#define tr4(a, b, c, d)       cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << endl
#define tr5(a, b, c, d, e)    cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << "\t|\t" << #e << ":\t" << e << endl
#define tr6(a, b, c, d, e, f) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << "\t|\t" << #e << ":\t" << e << "\t|\t" << #f << ":\t" << f << endl
#define base 999983
#define baseinv 943912055
#define ff first
#define ss second
using namespace std;
typedef long long ll;

ll powe(ll a, ll b, ll mod){
    ll res=1;
    while (b){
        if (b&1) res= (res *a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}
ll mmi ( ll n, ll m){
    return powe(n,m-2,m) % m;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int q; cin >> q;
    while ( q-- ){
        ll a, b, d, m, sum = 0;
        cin >> a >> b >> d >> m;
        ll n = (b - a - 1) / d + 1 ;
        if(a == b) n = 0;
        if (d & 1){
            ll st1 = a ^ 1, st2 = (a + d) ^ 1, n1 = max(n / 2, n - n/2), n2 = min(n / 2, n - n / 2);
            d <<= 1;
            sum = ((n1%m  * (((2 * st1) % m + (n1 - 1)%m * d) % m) % m) * mmi(2,m) ) % m;
            sum += ((n2%m  * (((2 * st2) % m + (n2 - 1)%m * d) % m) % m) * mmi(2,m) ) % m;
        }
        else{
            sum = ((n%m  * (((2 * (a ^ 1) % m) + (n - 1)%m * d) % m) % m) * mmi(2,m)  ) % m;
        }
        cout << sum % m << endl;
    }
    return 0;
}

