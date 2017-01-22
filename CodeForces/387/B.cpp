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

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n, req; string s;
    cin >> n >> s;
    unordered_map<char, int> mp;
    mp['A'] = 0, mp['C'] = 0, mp['G'] = 0, mp['T'] = 0;
    req = n >> 2;
    for(auto &it : s) if(it != '?') mp[it]++;
    for(auto &it : s){
        if(it == '?'){
            for(auto &jt : mp){
                if(jt.ss < req){
                    it = jt.ff, jt.ss++;
                    break;
                }
            }
        }
    }
    mp.clear();
    mp['A'] = 0, mp['C'] = 0, mp['G'] = 0, mp['T'] = 0;
    for(auto &it : s) if(it != '?') mp[it]++;
    bool flag = 1;
    if(n % 4 != 0) flag = 0;
    for(auto &it : mp) if(it.ss != req) flag = 0;
    if(flag) cout << s << endl;
    else cout << "===" << endl;
    return 0;
}

