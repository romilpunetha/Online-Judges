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
vector<ll>arr, brr;
ll n, m, x, ans;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int g; cin >> g; while(g--){
        cin >> n >> m >> x;
        ans = 0, arr.clear(), brr.clear(), arr.resize(n + 1), brr.resize(m + 1);
        arr[0] = brr[0]= 0;
        for(int i = 1; i <= n; i++) cin >> arr[i], arr[i] += arr[i - 1];
        for(int i = 1; i <= m; i++) cin >> brr[i], brr[i] += brr[i - 1];
        for(int i = 0; i <= n; i++){
            ll st = 0, en = m, mid, res = 0;
            while(st <= en){
                mid = (st + en) >> 1;
                if(arr[i] + brr[mid] <= x) res = i + mid, st = mid + 1;
                else en = mid - 1;
            }
            ans = max(ans, res);
        }
        cout << ans << endl;
    }
    return 0;
}

