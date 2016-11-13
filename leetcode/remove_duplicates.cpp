#include<bits/stdc++.h>
#define tr1(x)                cerr << #x << ":\t" << x << endl
#define tr2(x, y)             cerr << #x << ":\t" << x << "\t|\t" << #y << ":\t" << y << endl
#define tr3(x, y, z)          cerr << #x << ":\t" << x << "\t|\t" << #y << ":\t" << y << "\t|\t" << #z << ":\t" << z << endl
#define tr4(a, b, c, d)       cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << endl
#define tr5(a, b, c, d, e)    cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << "\t|\t" << #e << ":\t" << e << endl
#define tr6(a, b, c, d, e, f) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << "\t|\t" << #e << ":\t" << e << "\t|\t" << #f << ":\t" << f << endl
#define base 999983
#define baseinv 943912055
#define ff first
#define ss second
using namespace std;
typedef long long ll;
string util(string &s) {
    string res;
    int i = 0, k = -1;
    unordered_map<char, int> mp;
    while(s[i]) mp[s[i]] = i, i++;
    i  = 0;
    map<int, char> st;
    for(auto &it: mp) st[it.second] = it.first;
    while(!mp.empty()){
        char c = 'z' + 1;
        for(i = k + 1; i <= (*st.begin()).first; i++){
            if(mp.find(s[i]) != mp.end() && c > s[i]) c = s[i], k = i;
        }
        res = res + c;
        st.erase(mp[c]);
        mp.erase(c);
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    string s; cin>>s;
    cout << util(s) << endl;
    return 0;
}

