#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double D;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;

#define rd(x) scanf("%d",&x)
#define rd2(x,y) scanf("%d %d",&x,&y)
#define rl(x) scanf("%lld",&x)
#define rl2(x,y) scanf("%lld %lld",&x,&y)
#define wd(x) printf("%d" ,x)
#define wd2(x,y) printf("%d %d",x,y)
#define wl(x) printf("%lld",x)
#define wl2(x,y) printf("%lld %lld",x,y)
#define PC(x) putchar(x)
#define GC() getchar()
#define NL printf("\n")
#define SP printf(" ")

#define F first
#define S second
#define MP make_pair
#define PB push_back

#define fr(i,s,e) for(int i=s;i<e;i++)
#define frr(i,s,e) for(int i=s-1;i>=e;i--)
#define frv(i,a) for(int i = 0;i<(int)a.size();i++)
#define frvr(i,a) for(int i = a.size()-1;i>=0;i--)
#define tr(i,a) for(typeof(a.begin()) i = a.begin(); i != a.end();i++)

#ifdef LOCAL
#define E1(a) cout<<#a<<":" <<a<<endl;
#define E2(a,b) cout<<#a<<":" <<a<<" " <<#b<<":" <<b<<endl;
#define E3(a,b,c) cout<<#a<<":" <<a<<" " <<#b<<":" <<b<<" "<<#c<<":"<<c<<endl;
#define E4(a,b,c,d) cout<<#a<<":" <<a<<" " <<#b<<":" <<b<<" "<<#c<<":"<<c<< " "<<#d<< ":"<<d<<endl;
#define INP freopen("input","r",stdin);
#define OUT freopen("output","w",stdout);
#else
#define E1(a)
#define E2(a,b)
#define E3(a,b,c)
#define E4(a,b,c,d)
#define INP
#define OUT
#endif
#define maxn 100009
#define maxr 100009
ll mod = 1e9 + 7;
#define rw 3
#define co 3
int arr[maxn];
struct matrix{
    ll a[rw][co];
    int r,c;
    matrix(int n=0,int m=0){
        init(n,m);
    }
    void init(int n,int m){
        r = n;c = m;
    }
};

matrix operator*(matrix &a,matrix &b){
    matrix c(a.r,b.c);
    fr(i,0,c.r){
        fr(j,0,c.c){
            c.a[i][j] = 0;
            fr(k,0,a.c){
                c.a[i][j] += a.a[i][k]*b.a[k][j];
                c.a[i][j] %= mod;//remove mod if you don't want
            }
        }
    }
    return c;
}

matrix operator+(matrix &a,matrix &b){
    matrix c(a.r,a.c);
    fr(i,0,c.r){
        fr(j,0,c.c){
            c.a[i][j] = a.a[i][j] + b.a[i][j];
            if(c.a[i][j]>mod)c.a[i][j] -= mod;//remove mod if you don't want
        }
    }
    return c;
}

matrix operator-(matrix &a,matrix &b){
    matrix c(a.r,a.c);
    fr(i,0,c.r){
        fr(j,0,c.c){
            c.a[i][j] = a.a[i][j] - b.a[i][j];
            if(c.a[i][j]>mod)c.a[i][j] -= mod;//remove mod if you don't want
        }
    }
    return c;
}

matrix getI(int n){
    matrix c(n,n);
    fr(i,0,n)fr(j,0,n)c.a[i][j] = (i==j);
    return c;
}

matrix pw(matrix a,ll p){
    //p--;
    matrix x = getI(a.r);
    while(p){
        if(p&1){x = x*a;}
        a = a*a;
        p /=2;
    }
    return x;
}

matrix A,B,I;
matrix ans;

int main(){
    int test;rd(test);while(test--){
        I = getI(3);
        A = B = matrix(3,3);
        A.a[0][0] = 1;
        A.a[0][1] = 1;
        A.a[0][2] = 1;
        A.a[1][0] = 1;
        A.a[1][1] = 0;
        A.a[1][2] = 0;
        A.a[2][0] = 0;
        A.a[2][1] = 0;
        A.a[2][2] = 1;
        B.a[0][0] = 1;
        B.a[1][0] = B.a[2][0] = 1;
        B.a[1][0] = -1;
        ans  = matrix(3,3);
        fr(i,0,3)fr(j,0,3)ans.a[i][j] = 0;
        int n;
        rd(n);
        fr(i,1,n+1)rd(arr[i]);
        matrix D = I;
        frr(i,n+1,1){
            matrix E = pw(A,arr[i]);
            D = E*D;
            ans = ans + D;
            D = D + I;
        }
        for(int i = 0; i<3;i++){
            for(int j=0;j<3;j++){
                cout<<ans.a[i][j]<<" ";
            }
            cout<<endl;
        }
        ans = ans*B;
        ll a = ans.a[0][0];
        a = (a%mod + mod)%mod;
        cout<<a<<endl;
    }
    return 0;
}
