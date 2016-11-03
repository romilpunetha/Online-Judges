#include<bits/stdc++.h>
#define tr1(x)                cerr << #x << ":\t" << x << endl
#define tr2(x, y)             cerr << #x << ":\t" << x << "\t|\t" << #y << ":\t" << y << endl
#define tr3(x, y, z)          cerr << #x << ":\t" << x << "\t|\t" << #y << ":\t" << y << "\t|\t" << #z << ":\t" << z << endl
#define tr4(a, b, c, d)       cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << endl
#define tr5(a, b, c, d, e)    cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << "\t|\t" << #e << ":\t" << e << endl
#define tr6(a, b, c, d, e, f) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << "\t|\t" << #e << ":\t" << e << "\t|\t" << #f << ":\t" << f << endl
#define ff first
#define ss second
using namespace std;
typedef long long ll;
vector<vector<ll> > mat = {{1, 1}, {1, 0}}, fib = {{1, 0}, {1, 0}}, I = {{1,0},{0,1}};
int mod = 1e9 + 7;
int q, n;

vector<vector<ll> > add(auto a, auto b){
    vector<vector<ll> >res = {{0,0},{0,0}};
    for(int i = 0; i < 2; i++ ){
        for(int j = 0; j < 2; j++){
            res[i][j] = a[i][j] + b[i][j];
            res[i][j] %= mod;
        }
    }
    return res;
}

vector<vector<ll> > mul(auto a, auto b){
    vector<vector<ll> >res = {{0,0},{0,0}};
    for(int i = 0;i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                res[i][j] += a[i][k] % mod * b[k][j] % mod;
                res[i][j] %= mod;
            }
        }
    }
    return res;
}

vector<vector<ll> > exp(auto a, int b){
    if(b <= 0) return fib;
    vector<vector<ll> >res = {{1, 0}, {0, 1}};
    while(b){
        if(b & 1) res = mul(res,a);
        a = mul(a,a);
        b >>= 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>q; while(q--){
        cin>>n;
        ll ans = 0;
        vector<ll>arr(n);
        vector<vector<ll> > pre_sum = {{1,0},{0,1}}, tot_sum = {{0,0},{0,0}};
        for(int i = 0; i <n; i++){
            cin>> arr[i];
        }
        for(int i = 0; i < n; i++){
            auto curr = mul(pre_sum, exp(mat,arr[i]));
            tot_sum = add(tot_sum, mul(pre_sum,curr));
            pre_sum = add(mul(pre_sum, curr), I);
        }
        ans = tot_sum[0][0] + tot_sum[1][0];
        ans %= mod;
        cout<< ans <<endl;
    }
    return 0;
}

