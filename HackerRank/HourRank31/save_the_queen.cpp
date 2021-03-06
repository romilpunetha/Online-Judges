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
#define Pii P<int, int>
#define Pdi P<double, int>
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
void tr(){cout<<endl;}
template <typename H, typename...T> inline void tr(H head, T... tail){
    cerr << head << ' ';
    tr(tail...);
}
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ldbl;

int n, k;
V<double> arr;

void solve(){
    k--;
    PQ<Pdi, V<Pdi>, greater<Pdi> > pq;
    while(n) pq.push({arr[k], 1}), n--, k--;
    while(k >= 0){
        auto t = pq.top();
        pq.pop();
        while(!pq.empty() && pq.top().ff == t.ff) t.ss += pq.top().ss, pq.pop();
        t.ff += (arr[k] * 1.0) / t.ss;
        if(!pq.empty()){
            if(t.ff > pq.top().ff){
                double diff = t.ff - pq.top().ff;
                arr[k] = diff * t.ss;
                t.ff = pq.top().ff;
                k++;
            }
        }
        pq.push(t);
        k--;
    }
    cout << fixed << setprecision(6) << pq.top().ff << endl;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n >> k;
    arr.resize(k);
    for(auto &it : arr) cin >> it;
    sort(all(arr));
    solve();
    return 0;
}

