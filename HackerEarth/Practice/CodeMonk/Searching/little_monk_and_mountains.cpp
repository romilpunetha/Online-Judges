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

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n, q; cin >> n >> q;
    vector<pair<ll, ll> >arr(n + 2);
    arr[n + 1] = {LLONG_MAX, LLONG_MAX};
    vector<ll> pre(n + 2, 0);
    for(int i = 1; i <= n; i++){
        cin >> arr[i].ff >> arr[i].ss;
        pre[i] = pre[i - 1] + arr[i].ss - arr[i].ff + 1;
    }
    pre[n + 1] = pre[n] + 1;
    while(q--){
        ll x; cin >> x;
        int i = lower_bound(all(pre), x) - pre.begin();
        cout << arr[i].ff + x - pre[i - 1] - 1 << endl;
    }
    return 0;
}

