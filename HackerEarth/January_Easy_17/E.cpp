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

bool util(vector<bool> &a, vector<bool> &b){
    ll ans = 0;
    for(int i = 1; i <= 9; i++){
        if(a[i] && b[i]) ans = ans * 10 + i;
    }
    if(ans & 1) return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int test; cin >> test; while(test--){
        int n1, n2; cin >> n1 >> n2;
        string s;
        vector<vector<bool> > arr(n1, vector<bool>(10, 0)), brr(n2, vector<bool>(10, 0));
        for(auto &it : arr){
            cin >> s;
            int cnt = 0;
            for(auto &jt : s){
                jt -= 48;
                if(!it[jt]) it[jt] = 1, cnt++;
                if(cnt == 9) break;
            }
        }
        for(auto &it : brr){
            cin >> s;
            int cnt = 0;
            for(auto &jt : s){
                jt -= 48;
                if(!it[jt]) it[jt] = 1, cnt++;
                if(cnt == 9) break;
            }
        }
        double ans = 0.0;
        for(auto &it : arr){
            for(auto &jt : brr){
                ans += util(it, jt);
            }
        }
        ans = (ans * 1000) / (double)(n1 * n2);
        ans = round(ans);
        ans /= 1000;
        cout << fixed << setprecision(3) << ans << endl;
    }
    return 0;
}

