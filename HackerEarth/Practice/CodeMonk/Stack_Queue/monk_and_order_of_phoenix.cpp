#include<bits/stdc++.h>
#define endl '\n'
#define inf INT_MAX
#define pb push_back
#define present(c,x) ((c).find(x) != (c).end())
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

vector<stack<int> > arr;
vector<multiset<int> >mp;
int n;

bool check(){
    int prev = *( mp[1].begin() );
    for(int i = 2; i <= n; i++){
        auto it = mp[i].upper_bound(prev);
        if(it == mp[i].end()) return 0;
        prev = *it;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n;
    arr.resize(n + 2);
    mp.resize(n + 2);
    for(int i = 1; i <= n; i++){
        int size; cin >> size;
        while(size--){
            int t; cin >> t;
            arr[i].push(t);
            mp[i].insert(t);
        }
    }
    int q; cin >> q; while(q--){
        int choice; cin >> choice;
        if(choice == 0){
            int k; cin >> k;
            int t = arr[k].top();
            arr[k].pop();
            mp[k].erase(mp[k].find(t));
        }
        else if(choice == 1){
            int k, h; cin >> k >> h;
            arr[k].push(h);
            mp[k].insert(h);
        }
        else{
            if( check() ) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}

