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
    auto it = v.begin(); os << *it;for (++it; it != v.end(); os << ' ' << *it++); return os;
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

typedef struct Dsu {
    vector<ll> p, size, count;

    Dsu(int n){
        p.resize(n + 1);
        for(int i = 0; i <= n; i++) p[i] = i;
        size.resize(n + 1, 1);
        count.resize(n + 1, 1);
    }

    int get(int x) {
        return x == p[x]? x : (p[x] = get(p[x]));
    }

    bool merge(int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            p[x] = y;
            size[y] += size[x];
            count[y] += count[x] + 1;
            return true;
        } else{
            count[y]++;
            return false;
        }
    }
}Dsu;

int t, n, m;
V<int> u, v, w;


int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        Dsu d = Dsu(n);
        ll ans = 0;
        w.resize(m, 0);
        u = v = w;
        PQ<P<int, int> > pq;
        for(int i = 0; i < m; i++){
            cin >> u[i] >> v[i] >> w[i];
            pq.push({w[i], i});
        }
        while(!pq.empty()){
            P<int, int> t= pq.top();
            pq.pop();
            if(d.merge(u[t.ss], v[t.ss])) ans += t.ff;
        }
        cout << ans << endl;
    }
    return 0;
}

