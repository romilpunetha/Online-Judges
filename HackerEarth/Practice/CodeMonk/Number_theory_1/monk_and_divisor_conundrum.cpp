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
    int n; cin >> n;
    vector<int> arr(1e6 + 11, 0), res( 1e6 + 11, 0);
    for(int i = 0; i < n; i++){
        int t; cin >> t; arr[t]++;
    }
    for(ll i = 1; i < 1e6 + 10; i++){
        for(ll j = 1; i * j < 1e6 + 10; j++){
            res[i] += arr[i * j];
        }
    }
    int q; cin >> q; while(q--){
        ll r, s; cin >> r >> s;
        if(__gcd(r, s) == 1) cout << res[r] + res[s] - res[min((ll)1e6 + 10, r * s)]<< endl;
        else cout << res[min(r, s)] << endl;
    }
    return 0;
}

