#include<bits/stdc++.h>
#define endl '\n'
#define inf INT_MAX
#define pb push_back
#define present(c,x) ((c).find(x) != (c).end())
#define mod 1000000007
#define base 999983
#define baseinv 943912055
#define ff first
#define ss second
#define tr1(x)                cerr << #x << ": " << x << endl;
#define tr2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define tr3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define tr4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define tr5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define tr6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#define all(a) (a).begin(),(a).end()
using namespace std;
typedef long long ll;

struct C{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b){
        if(a.ff == b.ff) return a.ss < b.ss;
        return a.ff > b.ff;
    }
};

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n, k, t = 1, p; cin >> n >> k;
    set<pair<int, int>, C > st;
    while(n--){ cin >> p; st.insert({p, t++}); }
    while(k--){
        auto it = st.begin();
        cout << it -> ss << " ";
        st.erase(st.begin());
        if(it -> ff - 1 > 0) st.insert({it -> ff - 1, it -> ss});
    }
    return 0;
}

