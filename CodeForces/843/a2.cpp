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

bool tryMinimize(string s) {
    int len = s.length();
    int i = s.find("a", 1);
    if(i == string::npos || i == len - 1) return false;
    cout << s.substr(0, i) << " " << "a " << s.substr(i + 1) << endl;;
    return true;  
} 

bool tryMaximize(string s) {
    int len = s.length();
    int i = s.find("b", 1);
    cout << s.substr(0, i) << " " << s.substr(i, len - i - 1) << " " << s.substr(len - i) << endl;;
    return true;
}

void solve(string s) {
    if(s.find("a") == string::npos || s.find("b") == string::npos) {
        cout << s.substr(0,1) << " " << s.substr(1,1) << " " << s.substr(2) << endl;
        return; 
    }  
   bool flag = tryMinimize(s) || tryMaximize(s);
   if(!flag) cout << ":(" << endl;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int limit;
    cin >> limit;
    for(int i = 0; i < limit; i++) {
        string s;
        cin >> s;
        solve(s);
    } 
    return 0;
}

