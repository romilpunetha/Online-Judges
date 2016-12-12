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

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n, x; cin >> n >> x;
    queue<pair<int, int>> q1, q2;
    for(int i = 1; i <= n; i++ ){
        int t; cin >> t;
        q1.push({t, i});
    }
    int k = 0;
    while(k < x){
        int mx = -1, cnt = 0, ind;
        while(q1.size() && cnt < x){
            auto it = q1.front();
            q1.pop();
            if(mx < it.ff) mx = it.ff, ind = it.ss;
            q2.push(it);
            cnt++;
        }
        while(q2.size()){
            auto it = q2.front();
            q2.pop();
            if(it.ff == mx && it.ss == ind) continue;
            q1.push({max(it.ff - 1, 0), it.ss});
        }
        cout << ind << " ";
        k++;
    }
    return 0;
}

