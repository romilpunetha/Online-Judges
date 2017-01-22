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

unordered_map<ll, ll> mp;
ll hsh(ll n){
    int sum = 0, t = n;
    while(t){
        sum += t % 10;
        t /= 10;
    }
    return sum ^ n;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n; cin >> n;
    while(n--){
        ll t; cin >> t;
        ll val = hsh(t);
        mp[val]++;
    }
    map<ll, ll> mp2;
    ll mx = 0;
    int cnt = 0;
    for(auto &it : mp){
        if(!present(mp2, it.ss)) mp2[it.ss] = it.ff;
        else mp2[it.ss] = min(mp2[it.ss], it.ff);
        mx = max(mx, it.ff);
        cnt += it.ss - 1;
    }
    if(mp2.size() == 1) cout << mx << " " << cnt << endl;
    else cout << mp2.rbegin() -> ss << " " << cnt << endl;
    return 0;
}

