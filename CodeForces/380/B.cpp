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
int n, m;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n >> m;
    vector<vector<ll> >arr(n, vector<ll>(m)), ver, hor;
    for( int i = 0; i < n; i++ ){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    ver = hor = arr;
    for( int i = 0; i < n; i++ ){
        for(int j = 1; j < m; j++){
            hor[i][j] += hor[i][j - 1];
        }
    }
    for( int i = 1; i < n; i++ ){
        for(int j = 0; j < m; j++){
            ver[i][j] += ver[i - 1][j];
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j]) continue;
            if(ver[i][j])  ans++;
            if(ver[n - 1][j] - ver[i][j] > 0) ans++;
            if(hor[i][m - 1] - hor[i][j] > 0) ans++;
            if(hor[i][j]) ans++;
            //tr3(i, j, ans);
        }
    }
    cout << ans << endl;
    return 0;
}

