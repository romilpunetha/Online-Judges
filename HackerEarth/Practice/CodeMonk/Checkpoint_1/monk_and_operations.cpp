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
int n, m;

ll v1, v2, v3, v4;

ll util_row(vector<vector<ll>> &arr, ll val){
    ll sum = 0;
    for(int i = 0; i < n; i++){
        ll sum1 = 0, sum2 = 0;
        for(int j = 0; j < m; j++){
            sum1 += abs(arr[i][j]);
            sum2 += abs(arr[i][j] + val);
        }
        sum += max(max(sum1, sum2), m * v2) ;
    }
    return sum;
}

ll util_col(vector<vector<ll>> &arr, ll val){
    ll sum = 0;
    for(int i = 0; i < m; i++){
        ll sum1 = 0, sum2 = 0;
        for(int j = 0; j < n; j++){
            sum1 += abs(arr[j][i]);
            sum2 += abs(arr[j][i] + val);
        }
        sum += max(max(sum1, sum2), n * v4);
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n >> m;
    vector<vector<ll>>arr(n, vector<ll>(m, 0));
    ll sum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            sum += arr[i][j];
        }
    }
    cin >> v1 >> v2 >> v3 >> v4;
    ll res = max(util_row(arr, v1), util_col(arr, v3));
    cout << res << endl;
    return 0;
}

