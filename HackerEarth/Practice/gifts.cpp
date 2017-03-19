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
#define MS multiset
#define US unordered_set
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

V<ll> bit(1e6 + 10, 0);

void update(ll i, ll val){
    while(i < 1e6){
        bit[i] += val;
        i += i & -i;
    }
}

ll query(ll i){
    ll sum = 0;
    while(i){
        sum += bit[i];
        i -= i & -i;
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n, flag = 1; cin >> n;
    V<V<ll> >arr(5, V<ll>(n));
    V<ll> sum(5, 0);
    for(auto &it : arr) for(auto &jt : it) cin >> jt;
    for(int i = 0; s[i]; i++){
        update(i + 1, arr[s[i] - 'A'][i]);
        sum[s[i] - 'A'] += arr[s[i] - 'A'][i];
    }
    string s; cin >> s;
    int q; cin >> q; while(q--){
        char Q, R; cin >> Q >> R;
        if(R == 'e'){
            char x, y; cin >> x >> y;
            int p = x - 'A', q = y - 'A';
            swap(arr[p], arr[q]);
        }
        else if(R == 'c'){
            int x; char y; cin >> x >> y;
            s[x - 1] = y;
            flag = 1;
        }
        else{
            if(flag){
                for(int i = 0; s[i]; i++){
                    ll val = query(i + 1);
                    update(i + 1, -val);
                }
                flag = 0;
            }
            int x, y; cin >> x >> y;
            cout << query(y) - query(x - 1) << endl;
        }
    }
    return 0;
}

