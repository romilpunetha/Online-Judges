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

int n;
V<P<ll, ldbl> > arr;

ldbl util(ldbl mid){
    ldbl ans = 0.0;
    for(auto &it : arr){
        ldbl t = (abs(it.ff - mid) * 1.0) / it.ss;
        ans = max(ans, t);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++) cin >> arr[i].ff;
    for(int i = 0; i < n; i++) cin >> arr[i].ss;
    sort(all(arr));
    ldbl l = arr[0].ff, r = arr[n - 1].ff;
    while(ll(l * 1e7) < ll(r * 1e7)){
        ldbl mid1 = l + (r - l) / 3.0, mid2 = r - (r - l) / 3.0, mid = (r + l) / 2.0;
        ldbl ans = util(mid);
        ldbl ans1 = util(mid1);
        ldbl ans2 = util(mid2);
        if(ans >= ans1 && ans <= ans2) r = mid;
        else if(ans >= ans2 && ans <= ans1) l = mid;
        else l = mid1, r = mid2;
    }
    cout << fixed << setprecision(10) << util(l) << endl;
    return 0;
}

