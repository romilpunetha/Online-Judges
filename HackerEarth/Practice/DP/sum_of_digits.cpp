#include<bits/stdc++.h>
#define endl '\n'
#define inf INT_MAX
#define pb push_back
#define der(c, x) ((c).find(x) != (c).end())
#define base 999983
#define baseinv 943912055
#define ff first
#define ss second
#define V vector
#define Graph list<int>*
#define tr1(x)                cerr << #x << ": " << x << endl;
#define tr2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define tr3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define tr4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define tr5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define tr6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#define all(a) (a).begin(),(a).end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ldbl;

ll A, B, S;
V<ll> powe(16, 1);
V<V<ll> > dp(16, V<ll>(150, -1));
ll min_ans = -1;

ll util(ll prefix, ll digits, ll sum){
    if(sum < 0) return 0;
    ll mini = prefix, maxi = prefix + powe[digits] - 1;
    if( mini > B || maxi < A ) return 0;
    if( !digits ){
        if(sum > 0) return 0;
        if(min_ans == -1) min_ans = prefix;
        return 1;
    }
    bool flag = (mini >= A && maxi <= B);
    if(flag && dp[digits][sum] != -1) return dp[digits][sum];
    ll ret = 0;
    for(int i = 0; i < 10; i++){
        ret += util(prefix + i * powe[digits - 1], digits - 1, sum - i);
    }
    if(flag) dp[digits][sum] = ret;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    for(int i = 1; i < 16; i++) powe[i] = powe[i - 1] * 10;
    cin >> A >> B >> S;
    cout << util(0, 15, S) << endl;
    cout << min_ans << endl;
    return 0;
}

