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

int n, q;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n >> q;
    set<int>st;
    map<int, list<int> >mp;
    for(int i = 1; i <= n; i++) st.insert(i);
    for(int i = 0; i < q; i++){
        int ti, ki, di; cin >> ti >> ki >> di;
        while(!mp.empty() && (mp.begin())->ff < ti){
            auto jt = mp.begin();
            for(auto &it : jt->ss) st.insert(it);
            mp.erase(mp.begin());
        }
        if(ki > st.size()) cout << -1 << endl;
        else{
            int sum = 0;
            for(int j = 0; j < ki; j++){
                int t = *(st.begin());
                mp[ti + di - 1].push_back(t);
                st.erase(st.begin());
                sum += t;
            }
            cout << sum << endl;
        }
    }
    return 0;
}

