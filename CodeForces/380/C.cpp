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
ll n, k , s, t;
vector<ll>st;

bool is_valid(ll c){
    ll time = 0;
    for(int i = 1; i < k + 2; i++){
        ll dist = st[i] - st[i - 1];
        if(dist > c) return false;
        ll x = min(dist, c - dist);
        time += x + 2 * (dist - x);
    }
    if(time <= t) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n >> k >> s >> t;
    vector<pair<ll,ll> >arr(n);
    st = vector<ll>(k + 2);
    for(auto &it : arr) cin >> it.ff >> it.ss;
    for(int i = 1; i <= k; i++) cin >> st[i];
    st[0] = 0, st[k+1] = s;
    sort(st.begin(), st.end());
    ll st = 0, ed = INT_MAX, mid, val = INT_MAX, ans = INT_MAX;
    while(st <= ed){
        mid = st + (ed - st) / 2;
        if( is_valid( mid ) ) val = mid, ed = mid - 1;
        else st = mid + 1;
    }
    for(auto &it : arr) if(it.ss >= val) ans = min(ans, it.ff);
    if(ans == INT_MAX) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}

