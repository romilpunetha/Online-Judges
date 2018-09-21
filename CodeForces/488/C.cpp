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

V<P<int, int> > arr(4), brr(4);

bool eq1(int i, int j){
    int y = i + brr[2].ss - brr[2].ff;
    if(j - y > 0) return false;
    return true;
}

bool eq2(int i, int j){
    int y = -i + brr[2].ss + brr[2].ff;
    if(j - y <= 0) return true;
    return false;
}

bool eq3(int i, int j){
    int y = i + brr[3].ss - brr[3].ff;
    if(j - y >= 0) return true;
    return false;
}

bool eq4(int i, int j){
    int y = -i + brr[0].ff + brr[0].ss;
    if(j - y >= 0) return true;
    return false;
}

bool check(int i, int j){
    bool a = eq1(i, j);
    bool b = eq2(i, j);
    bool c = eq3(i, j);
    bool d = eq4(i, j);
    return a && b && c && d;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    for(auto &it : arr) cin >> it.ff >> it.ss;
    for(auto &it : brr) cin >> it.ff >> it.ss;
    sort(all(brr));
    int min_x = INT_MAX, max_x = INT_MIN, min_y = INT_MAX, max_y = INT_MIN;
    for(auto &it : arr) min_x = min(min_x, it.ff), max_x = max(max_x, it.ff), min_y = min(min_y, it.ss), max_y = max(max_y, it.ss);
    bool flag = 0;
    for(int i = min_x; i <= max_x; i++){
        for(int j = min_y; j <= max_y; j++){
            flag |= check(i, j);
        }
    }
    if(flag) cout << "YES";
    else cout << "NO";
    return 0;
}

