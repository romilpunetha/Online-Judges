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
ll mod = 1e9 + 9;

ll cnt[105][205];

int main(){
    ll i,j,x,ans,n;
    cin>> n;
    ans = n + 1;
    for(i = 0;i<n;i++){
        cin>> x;
        for(j = 0;j<=100;j++){
            cnt[x][x-j+100] += cnt[j][x - j+100];
            cnt[x][x-j+100] %= mod;
        }
        for(j = -100;j<=100;j++){
            cnt[x][j + 100]++;
            cnt[x][j+100] %= mod;
            ans --;
        }
    }
    ans = (ans + mod) % mod;
    for(i = 1;i<=100;i++){
        for(j = -100;j<=100;j++){
            ans = (ans + cnt[i][j+100]) % mod;
        }
    }
    ans = (ans + mod) % mod;
    cout<<ans<<endl;
    return 0;
}
