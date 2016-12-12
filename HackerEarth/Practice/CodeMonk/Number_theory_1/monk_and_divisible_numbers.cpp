#include<bits/stdc++.h>
#define endl '\n'
#define inf INT_MAX
#define pb push_back
#define present(c,x) ((c).find(x) != (c).end())
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

ll mod = 1e9 + 7;
ll A, B, C;
unordered_map<ll,ll> mp1, mp2;

ll expo(ll a, ll b){
    ll res = 1;
    while (b){
        if (b & 1) res = (res * a) % mod;
        a = ( a * a ) % mod;
        b >>= 1;
    }
    return res % mod;
}

void factor(ll a, int  p)
{
    if( p == 0 ){
        for(ll i = 2; i * i <= a; i++){
            if(a % i == 0){
                while(a % i == 0){
                    mp1[i]++;
                    a/=i;
                }
            }
        }
        if(a>1){
            mp1[a]++;
        }
    }
    else
    {
        for(ll i = 2; i * i <= a; i++){
            if(a % i == 0){
                while( a % i == 0){
                    mp2[i]++;
                    a/=i;
                }
                mp2[i]*=C;
            }
        }
        if(a > 1){
            mp2[a]++;
            mp2[a]*=C;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int test; cin >> test; while(test--){
        mp1.clear(), mp2.clear();
        cin >> A >> B >> C;
        factor(A, 0);
        factor(B, 1);
        for(auto &it : mp2){
            if(mp1[it.ff]){
                if(mp1[it.ff] <= it.ss) mp2[it.ff] = it.ss - mp1[it.ff];
                else mp2[it.ff] = 0;
            }
        }
        ll res = 1, tp, val, ans;
        for(auto &it : mp2){
            tp = it.ss, val = it.ff % mod;
            if(tp > 0) {
                ans = expo(val, tp);
                res *= ans;
                res %= mod;
            }
        }
        cout << res << endl;
    }
    return 0;
}


