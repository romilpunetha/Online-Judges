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

vector<int> bit(1e6, 0);

void update(int i, int val){
    while(i < 1e6){
        bit[i] += val;
        i += i & -i;
    }
}

int query(int i){
    int sum = 0;
    while(i){
        sum += bit[i];
        i -= i & -i;
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int test; cin >> test; while(test--){
        int n; cin >> n;
        multiset<pair<int, int> >mp;
        for(int i = 1; i <= n; i++){
            int t; cin >> t; mp.insert({t, i});
            update(i, 1);
        }
        int up = 0, dn = 0;
        while(mp.size() > 1){
            auto it = mp.begin();
            int val = it->ff, ind = it->ss;
            val -= up;
            dn = query(ind);
            int k = val / dn;
            if(val == 0 || val % dn) k++;
            up += k * dn;
            while(!mp.empty() && (it->ff) - up < 0){
                ind = it->ss;
                update(ind, -1);
                mp.erase(mp.begin());
                it = mp.begin();
            }
        }
        if(mp.empty()) cout << "Kushagra\n";
        else{
            int ind = (mp.begin())->ss;
            update(ind, -1);
            cout << "Ladia\n";
        }
    }
    return 0;
}

