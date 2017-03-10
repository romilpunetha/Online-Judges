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
#define L list
#define P pair
#define M map
#define S set
#define UM unordered_map
#define MM multimap
#define UMM unordered_multimap
#define MS multiset
#define US unordered_set
#define UMS unordered_multiset
#define PQ priority_queue
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
int n;
V<int> gas, cost;

int solve(){
    if(n == 0) return -1;
    int tank = 0, i = 0, j = 0;
    while(1){
        if(j >= n) return i;
        int net;
        if (i + j >= n) net = gas[i + j - n] - cost[i + j - n];
        else net = gas[i + j] - cost[i + j];
        if(tank + net < 0){
            j++;
            i = i + j;
            if(i >= n) return -1;
            tank = 0;
            j = 0;
        }
        else {
            tank += net;
            j++;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n; cin >> n;
    gas.resize(n);
    cost = gas;
    for(auto &it : gas) cin >> it;
    for(auto &it : cost) cin >> it;
    cout << solve() << endl;
    return 0;
}

