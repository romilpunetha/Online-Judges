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
int n,  m, ans = INT_MIN;
int a[105], b[105], c[105], d[105];
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n >> m;
    a[0] = 0;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i] >> c[i];
    for(int i = 1; i <= n; i++) a[i] += a[i - 1];
    for(int i = 0; i < m; i++) d[i] = a[c[i]] - a[b[i] - 1];
    sort(d, d + m);
    ll ans = 0;
    for(int i = m - 1; i >= 0; i--){
        if(d[i] >= 0) ans += d[i];
    }
    cout << ans << endl;
    return 0;
}

