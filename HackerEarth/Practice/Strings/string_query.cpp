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

V<V<int> > bit(30, V<int>(1e6 + 10));
V<bool> visited(1e6 + 10,0);

void update(int i, int ind, int val){
    while(ind <= 1e6){
        bit[i][ind] += val;
        ind += ind & -ind;
    }
}

int query(int i, int ind){
    int sum = 0;
    while(ind){
        sum += bit[i][ind];
        ind -= ind & -ind;
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    string s; cin >> s;
    int len = s.length();
    for(int i = 0; i < len; i++) update(s[i] - 'a', i + 1, 1);
    int q; cin >> q; while(q--){
        int k; char l; cin >> k >> l;
        int st = 1, en = len, mid, ans = -1;
        while(st <= en){
            mid = (st + en) >> 1;
            int t = query(l - 'a', mid);
            if(k <= t)  en = mid - 1, ans = mid;
            else st = mid + 1;
        }
        if(ans != -1){
            update(l - 'a', ans, -1);
            visited[ans - 1] = 1;
        }
    }
    for(int i = 0; i < len; i++){
        if(!visited[i]) cout << s[i];
    }
    cout << endl;
    return 0;
}

