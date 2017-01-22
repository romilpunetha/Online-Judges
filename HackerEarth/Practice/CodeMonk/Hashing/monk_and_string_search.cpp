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
ll n;
vector<string>arr;
vector<unsigned long long>len, pwr(1e6);
vector<vector<unsigned long long> > pre;

bool util(unsigned long long hval, int sz){
    bool flag = 1;
    for(int i = 1; i < n; i++){
        flag = 0;
        unsigned long long hval2 = 0;
        hval2 = pre[i][sz - 1];
        if(hval == hval2) continue;
        for(int j = 1; j + sz - 1 < len[i]; j++){
            hval2 = pre[i][j + sz - 1] - pre[i][j - 1] * pwr[sz];
            if(hval == hval2){ flag = 1; break; }
        }
        if(!flag) return false;
    }
    return true;
}

bool valid(int sz){
    unsigned long long hval = 0;
    hval = pre[0][sz - 1];
    if(util(hval, sz)) return true;
    for(int i = 1; i + sz - 1 < len[0]; i++){
        hval = pre[0][i + sz - 1] - pre[0][i - 1] * pwr[sz];
        if(util(hval, sz)) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll mn = inf; cin >> n;
    arr.resize(n); len.resize(n); pre.resize(n);
    pwr[0] = 1;
    for(int i = 1; i < 1e6; i++){
        pwr[i] = pwr[i - 1] * base;
    }
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        len[i] = arr[i].length();
        pre[i].resize(len[i]);
        mn = min(mn, (ll)len[i]);
    }
    for(int i = 0; i < n; i++){
        unsigned long long hval = 0;
        for(int j = 0; j < len[i]; j++){
            hval = hval * base + arr[i][j];
            pre[i][j] = hval;
        }
    }
    int st = 1, en = mn, mid, ans = 0;
    while(st <= en){
        mid = (st + en) / 2;
        //tr1(mid);
        if(valid(mid)) ans = mid, st = mid + 1;
        else en = mid - 1;
    }
    cout << ans << endl;
    return 0;
}

