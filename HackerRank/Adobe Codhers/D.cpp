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
int mod = 1e9 + 7;
struct matrix{
    ll n, m;
    vector<vector<ll> > mat;

    matrix(){
        ;
    }

    matrix(int x, int y = 0, int iden = 0){
        n = x; m = y;
        if(y==0) m = n;
        mat = vector<vector<ll> >(n, vector<ll>(m, 0));
        if(iden) for(int i = 0; i < n; i++) mat[i][i] = 1LL;
    }

    void out(){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

matrix operator *(const matrix &a,const matrix &b){
    int p = a.n, q = a.m, r = b.m;
    matrix c = matrix(p, r);
    for(int i = 0; i < p; i++){
        for(int j = 0; j < r; j++){
            ll &val = c.mat[i][j];
            for(int k = 0; k < q; k++){
                val = (val + (a.mat[i][k] * 1LL * b.mat[k][j]) % mod );
                val %= mod;
            }
        }
    }
    return c;
}

matrix expo(matrix a,ll b,int MOD = mod){
    matrix res = matrix(a.n, a.n, 1);
    while(b){
        if(b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    ll n; cin >> n;
    matrix M = matrix(2, 2, 0);
    M.mat[0][0] = 1LL;
    M.mat[0][1] = 1LL;
    M.mat[1][0] = 1LL;
    M.mat[1][1] = 0LL;
    matrix B = expo(M,n);
    cout << (B.mat[0][1] % mod + (2 * B.mat[1][1]) % mod) % mod << endl;
    return 0;
}

