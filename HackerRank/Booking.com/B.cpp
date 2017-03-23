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

struct C{
    bool operator()(const P<int, int> &a, const P<int, int> &b){
        if(a.ss == b.ss) return a.ff < b.ff;
        return a.ss > b.ss;
    }
};

V<string> arr(1e6);
int k = 0;

void parse(string &s, char delim){
    s += delim;
    int prev = 0, curr  = 0, len = s.length();
    for(int i = 0; i < len; i++) s[i] = tolower(s[i]);
    while((curr = s.find(delim, prev)) != string::npos){
        string subst = s.substr(prev, curr - prev);
        prev = curr + 1;
        if(!(subst[curr - prev - 1] >= 'a' && subst[curr - prev - 1]  <= 'z')) subst.pop_back();
        arr[k++] = subst;
    }
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    UST<string> st;
    string t;
    getline(cin, t);
    parse(t, ' ');
    for(int i = 0; i < k; i++) st.insert(arr[i]);
    UM<int, int> mp;
    ST<P<int, int>, C> stt;
    getline(cin, t);
    int m = stoi(t); while(m--){
        int id, len; cin >> id;
        getline(cin, t);
        parse(t, ' ');
        for(int i = 0; i < k; i++) if(der(st, arr[i])) mp[id]++;
        stt.insert({id, mp[id]});
    }
    for(auto &it : stt) cout << it.ff << " ";
    return 0;
}

