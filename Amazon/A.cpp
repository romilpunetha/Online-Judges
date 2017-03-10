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
#define M map
#define S set
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

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n;
    V<int> arr(n), brr;
    for(auto &it : arr) cin >> it;
    brr = arr;
    for(auto &it : arr){
        if(it == 0) it = 1;
        else it = -1;
    }
    ll msf = INT_MIN, ed = 0, st = 0, med = 0, s = 0;
    for(int i = 0; i < n; i++){
        med += arr[i];
        if(msf < med){
            msf = med;
            st = s;
            ed = i;
        }
        if(med < 0){
            med = 0;
            s = i + 1;
        }
    }
    ll ans = 0;
    for(int i = st; i <= ed; i++){
        if(brr[i] == 0) brr[i] = 1;
        else brr[i] = 0;
    }
    for(auto &it : brr) ans += it;
    cout << ans << endl;
    return 0;
}

