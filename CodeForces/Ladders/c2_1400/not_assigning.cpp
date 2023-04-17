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
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
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

int prime[] = {2, 5};

void dfs(int idx, int k, MP<Pii, int> &mp, Vi &ans, V<bool> &visited, Graph &g) {
    visited[idx] = true;
    for(auto &it : g[idx]) {
        if(visited[it]) continue;
        int p = idx, q = it;
        if(p > q) swap(p, q);
        int i = mp[{p, q}];
        ans[i] = prime[k];
        k = (k + 1) % 2;
        dfs(it, k, mp, ans, visited, g);
    }
}

void solve() {
    int n; cin >> n;
    Vi arr(n + 1, 0);
    MP<Pii, int> mp;
    Vi ans(n - 1);
    V<bool> visited(n + 10, false);
    bool flag = true;
    Graph g(n + 10);
    for(int i = 0; i < n - 1; i++) {
        int p, q; cin >> p >> q;
        if(p > q) swap(p, q);
        arr[p]++, arr[q]++;
        if(arr[p] > 2 || arr[q] > 2) flag = false;
        mp[{p, q}] = i;
        g[p].push_back(q);
        g[q].push_back(p);
    }
    if(!flag) { 
        cout << -1 << endl;
        return;
    }
    dfs(1, 0, mp, ans, visited, g);
    for(auto &it : ans) cout << it << " "; cout << endl; 
}
 
int main(){ 
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int T; cin >> T; while(T--) solve();
    return 0;
}