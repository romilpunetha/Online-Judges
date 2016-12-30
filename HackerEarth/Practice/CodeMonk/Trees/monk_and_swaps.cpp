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
int n, t = 0;
vector<int>arr, pre;
unordered_map<int, int> mp;

void prefix(int ind){
    if(ind >= n) return;
    prefix(ind * 2 + 1);
    pre[t++] = arr[ind];
    prefix(ind * 2 + 2);
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int ans = 0; cin >> n;
    arr.resize(n);
    pre.resize(n);
    for(auto &it : arr) cin >> it;
    prefix(0);
    sort(all(arr));
    for(int i = 0; i < n; i++) mp[pre[i]] = i;
    int i = 0;
    while(i < n){
        if(pre[i] == arr[i]) i++;
        else{
            mp[pre[i]] = mp[arr[i]];
            swap(pre[i], pre[mp[arr[i]]]);
            mp[pre[i]] = i;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

