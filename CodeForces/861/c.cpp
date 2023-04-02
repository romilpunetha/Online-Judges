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

int get(ll n) {
    int mx = INT_MIN, mn = INT_MAX;
    while(n) {
        int t = n % 10;
        mx = max(mx, t);
        mn = min(mn, t);
        n = n / 10;
    }
    return mx - mn;
}

int get(vector<int> &a, vector<int> &b) {
    int x = *max_element(all(a));
    int y = *min_element(all(b));
    return x - y;
}

vector<int> getV(ll n) {
    vector<int> arr;
    while(n) {
        int t = n % 10;
        n /= 10;
        arr.push_back(t);
    }
    return arr;
}

ll make(vector<int> &arr, int i) {
    ll n = 0;
    for(; i < arr.size(); i++) {
        n = n * 10 + arr[i];
    }
    return n;
}

ll solve() {
   ll p, q; cin >> p >> q;
   vector<int> a = getV(p);
   vector<int> b = getV(q);
   int diff = b.size() - a.size();
   while(diff) {
    a.push_back(0);
    diff--;
   }
   reverse(a.begin(), a.end());
   reverse(b.begin(), b.end());

    int i = 0, mx = -1, mn = 100;
    for(; i < a.size(); i++) {
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
        if(b[i] != a[i]) break;
    }

    if(i == a.size()) return p;

    if(a[0] != 0) {
        int diff = 10;
        ll res;
        for(int k = a[i]; k <= b[i]; k++) {
            a[i] = k;
            for(int t = 0; t <= 9; t++) {
                for(int j = i + 1; j < a.size(); j++) {
                    a[j] = t;
                }
                ll b = make(a, 0);
                int d = get(b);
                if(b >= p && b <= q && diff > d) {
                    diff = d;
                    res = b;
                }
            }
        }
        return res;
    } else {
        while(a[i] == 0) i++;
        while(i < a.size()) {
            a[i] = 9;
            i++;
        }
        return make(a, 0);
    }
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T;
    cin >> T;
    while(T--) { 
        cout << solve() << endl;
    }
    return 0;
}

