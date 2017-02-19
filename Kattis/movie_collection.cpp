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
vector<int> bit;

void update(int i, int val){
    while(i < 2e6 + 10){
        bit[i] += val;
        i += i & -i;
    }
}

int query(int i){
    int sum = 0;
    while(i){
        sum += bit[i];
        i -= i & -i;
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int test; cin >> test; while(test--){
        bit.clear(); bit.resize(2e6 + 10, 0);
        int n, k; cin >> n >> k;
        unordered_map<ll, ll> mp;
        ll map_min = 1e6;
        for(int i = 1; i <= n; i++){
            mp[i] = 1e6 + i;
            update(mp[i], 1);
        }
        while(k--){
            int t; cin >> t;
            int p = mp[t];
            cout << query(p - 1) << " ";
            update(p, -1);
            mp[t] = map_min--;
            update(mp[t], 1);
        }
        cout << endl;
    }
    return 0;
}

