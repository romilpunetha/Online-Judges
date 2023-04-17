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
#define Vi V<int>
#define Vll V<ll>
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
#define Pii P<int, int>
#define Pll P<long long, long long>
#define Graph V<L<int> >
#define all(a) (a).begin(),(a).end()
#define tr1(x)                cerr << #x << ": " << x << endl;
#define tr2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define tr3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define tr4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define tr5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define tr6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
using namespace std;
template <typename A, typename B> inline ostream& operator<<(ostream&os, const pair<A, B> &v) {return os << v.first << ' ' << v.second;}
template <typename A> inline ostream& operator<<(ostream&os, const vector<A> &v){
    auto it = v.begin(); 
    os << *it;
    for (++it; it != v.end(); 
    os << ' ' << *it++); 
    return os; 
}
void tr(){cout<<endl;}
template <typename H, typename...T> inline void tr(H head, T... tail){
    cerr << head << ' ';
    tr(tail...);
}
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ldbl;

ll accurateFloor(ll a, ll b) {
	ll val = a / b;
	while (val * b > a)
		val--;
	return val;
} 
 
bool util(Vll &pre, ll k, ll sum, ll val, int i) {
    return val <= accurateFloor(k - sum + pre[i], i + 1);
}

int solve() {
    ll n, k; cin >> n >> k;
    Vll arr(n), pre(n); 
    for(auto &it : arr) cin >> it;
    
    sort(all(arr));
    reverse(all(arr));

    pre[0] = arr[0];
    for(int i = 1; i < n; i++) pre[i] = arr[i] + pre[i - 1];
    if(pre[n - 1] <= k) return 0;
    ll res = pre[n - 1] - k;

    for(int i = 0; i < n - 1; i++) {
        ll start = 0, end = pre[n - 1] - k, mid, ans = 0; 
        while(start <= end) {
            mid = (start + end) >> 1;
            if(util(pre, k, pre[n - 1] - mid, arr[n - 1] - mid, i)) ans = mid, end = mid - 1;
            else start = mid + 1;
        }
        res = min(res, ans + i + 1);
    }
    return res;
}
 
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T; cin >> T; while(T--) cout << solve() << endl; 
    return 0;
}