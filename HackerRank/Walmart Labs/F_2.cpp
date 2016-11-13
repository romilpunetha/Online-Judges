#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pll;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pll>		vpll;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
int mod = 1000000007;
const int N = 3e5;
vi g[N];
int a[N];
int mpow(int base, int exp);
void ipgraph(int n, int m);
void dfs(int u, int par);
struct matrix{
    int n, m;
    vector<vi> mat;
    matrix(){
        ;
    }
    matrix(int x, int y = 0, int iden = 0){
        n = x; m = y;
        if(y==0) m = n;
        mat = vector<vi>(n, vi(m, 0));
        if(iden){
            int i;
            fo(i, n) mat[i][i] = 1;
        }
    }
    void out(){
        int i, j;
        fo(i, n){fo(j, m)cout<<mat[i][j]<<" ";cout<<endl;}
    }
    int rowsum(int x){
        int i;
        int ans = 0;
        fo(i, m){
            ans += mat[x][i];
            if (ans>=mod) ans -= mod;
        }
        return ans;
    }
    int colsum(int x){
        int i;
        int ans = 0;
        fo(i, n){
            ans += mat[i][x];
            if (ans>=mod) ans -= mod;
        }
        return ans;
    }
};
matrix operator *(matrix a, matrix b){
    matrix c = matrix(a.n);
    int i, j, k, n = c.n;
    fo(i, n)fo(j, n){
        int &val = c.mat[i][j];
        val = 0;
        fo(k, n){
            val += (a.mat[i][k]*1LL*b.mat[k][j])%mod;
            if (val >= mod) val -= mod;
        }
    }
    return c;
}
matrix operator *(int a, matrix b){
    matrix c = matrix(b.n);
    int i, j, k, n = c.n;
    fo(i, n)fo(j, n){
        int &val = c.mat[i][j];
        val = a*b.mat[i][j];
        val %= mod;
    }
    return c;
}
matrix mul (matrix &a, matrix &b){
    matrix c = matrix(a.n);
    int i, j, k, n = c.n;
    fo(i, n)fo(k, n){
        fo(j, n){
            int &val = c.mat[i][j];
            val += (a.mat[i][k]*1LL*b.mat[k][j])%mod;
            if (val >= mod) val -= mod;
        }
    }
    return c;
}
matrix add (matrix &a, matrix &b){
    int i, j, k, n = a.n;
    matrix c(n, n, 0);
    fo(i, n)fo(j, n){
        int &val = c.mat[i][j];
        val = (a.mat[i][j]+b.mat[i][j]);
        if (val >= mod) val -= mod;
    }
    return c;
}
matrix operator +(matrix a, matrix b){
    matrix c = matrix(a.n);
    int i, j, k, n = c.n;
    fo(i, n)fo(j, n){
        int &val = c.mat[i][j];
        val = (a.mat[i][j]+b.mat[i][j]);
        if (val >= mod) val -= mod;
    }
    return c;
}
matrix operator -(matrix a, matrix b){
    matrix c = matrix(a.n);
    int i, j, k, n = c.n;
    fo(i, n)fo(j, n){
        int &val = c.mat[i][j];
        val = (a.mat[i][j]-b.mat[i][j]);
        if (val >= mod) val -= mod;
        if (val < 0) val += mod;
    }
    return c;
}
matrix operator %(matrix M, int MOD)
{
    matrix temp(M.n);
    for(int i=0;i<M.n;i++)
        for(int j=0;j<M.n;j++)
            temp.mat[i][j]=M.mat[i][j]%MOD;
    return temp;
}
matrix tem;
matrix p(matrix &n,int m,int MOD = mod)
{
    if(m==0)
        return matrix(n.n,n.n, 1);
    matrix x=p(n,m/2,MOD);
    if(m%2==0)
        return tem=mul(x,x);
    else
        return tem = mul(x, tem=mul(x,n));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,k,j,m, t;
    si(t);
    while(t--){
        si(n);
        fo(i, n) si(a[i]);
        matrix D = matrix(2, 2, 0);
        matrix ID(2,2,1);
        matrix M = matrix(2, 2, 0);
        M.mat[0][0] = 1;
        M.mat[0][1] = 1;
        M.mat[1][0] = 1;
        M.mat[1][1] = 0;
        matrix B, BB, ANS, DP(2, 2, 0);

        ll ans = 0;
        Fo(i, n-1, -1){
            //ID + D*M
            B=p(M, a[i]);
            // cout<<a[i]<<" -> "<<2*B.mat[0][0]-1<<endl;
            // ANS = B*DP ;
            // cout<<ANS.mat[0][0]<<endl;
            DP = B*(ID + DP);
            ans += DP.mat[0][1];
        }
        if (ans >= mod) ans %= mod;
        pl(ans);
    }
    return 0;
}


