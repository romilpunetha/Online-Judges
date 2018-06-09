#include<bits/stdc++.h>
#define endl '\n'
#define inf INT_MAX
#define pb push_back
#define der(c, x) ((c).find(x) != (c).end())
#define base 999983
#define baseinv 943912055
#define ff first
#define ss second
#define V vector
#define L list
#define P pair
#define MP map
#define ST set
#define UM unordered_map
#define MM multimap
#define UMM unordered_multimap
#define MST multiset
#define UST unordered_set
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

ll min(ll a, ll b){
    return a < b? a : b;
}

int n;
V<ll> size, cost, mid, ans;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n;
    size.resize(n, 0), cost.resize(n, 0), mid.resize(n, inf), ans.resize(n, inf);
    for(auto &it: size) cin >> it;
    for(auto &it: cost) cin >> it;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++)
            if(size[i] < size[j])
                mid[j] = min(mid[j], cost[i] + cost[j]);
    }
    for(int i = 1; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(mid[i] != inf && size[i] < size[j]) ans[j] = min(ans[j], mid[i] + cost[j]);
        }
    }
    int out = inf;
    for(auto &it: ans) out = min(out, it);
    if(out == inf) cout << -1 << endl;
    else cout << out << endl;
    return 0;
}

