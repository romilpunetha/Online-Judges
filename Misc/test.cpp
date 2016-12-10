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

ll maxsum(ll n, ll arr[]){
    if(n == 1) return arr[0];
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll temp[n - 1];
        ll l = i - 1 >= 0? arr[i - 1] : 1;
        ll r = i + 1 < n? arr[i + 1] : 1;
        for(int j = 0, c = 0; j < n; j++){
            if(j == i) continue;
            temp[c++] = arr[j];
        }
        ans = max(ans, l * r + maxsum(n - 1, temp));
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int test; cin >> test;
    for(int i = 1; i <= test; i++){
        cout << "#" << i << " ";
        int n;
        cin >> n;
        ll arr[n];
        for(int i = 0; i < n; i++) cin >> arr[i];
        cout << maxsum(n, arr) << endl;
    }
    return 0;
}

