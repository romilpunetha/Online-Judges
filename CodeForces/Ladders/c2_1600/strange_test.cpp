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
 
int ans;
 
void util(int a, int b, int idx, int count) {
    if(idx > 21) {
        ans = min(ans, a == b ? count : count + 1);
        return;
    };
    
    int a_bit = a & (1 << idx);
    int b_bit = b & (1 << idx);
    
    int shift = (1 << idx);
    int l = (a & (shift - 1));
    int k = shift - l;
    
    if(a_bit == b_bit) util(a, b, idx + 1, count);
    else if(a_bit > b_bit) {
        util(a + k , b, idx + 1, count + k);
        util(a, b + shift, idx + 1, count + shift);
    }
    else {
        util(a + k , b, idx + 1, count + k);
        util(a , b + shift, idx + 1, count + shift);
        util(a | b, b, idx + 1, count + 1);
    }
} 
 
void solve() {
    ans = INT_MAX;
    int a, b; cin >> a >> b; 
    util(a, b, 0, 0);
    cout << ans << endl;
}
 
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T; cin >> T; while(T--) solve();
    return 0;
}