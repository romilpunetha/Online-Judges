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

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll n, m, k, x, s; cin >> n >> m >> k >> x >> s;
    vector<pair<ll,ll> >mm(m), kk(k);
    for(auto &it : mm) cin >> it.ff;
    for(auto &it : mm) cin >> it.ss;
    for(auto &it : kk) cin >> it.ff;
    for(auto &it : kk) cin >> it.ss;
    ll ans = n * x;
    for(auto &it : kk){
        if(it.ss <= s) ans = min(ans, max(0LL, (n - it.ff) * x));
    }
    for( auto &it : mm ){
        ll &time = it.ff, &cost = it.ss;
        if(cost <= s) ans = min(ans, n * time);
        int lo = 0, hi = k - 1;
        while(lo < hi){
            int mid = (hi + lo) >> 1;
            if(cost + kk[mid].ss > s) hi = mid;
            else{
                ll tot = (n - kk[mid].ff) * time;
                ans = min(ans, tot);
                lo = mid + 1;
            }
        }
        if(cost + kk[lo].ss <= s){
            ll tot = (n - kk[lo].ff) * time;
            ans = min(ans, tot);
        }
    }
    cout << ans << endl;
    return 0;
}

