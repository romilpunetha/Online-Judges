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
#define MP map
#define ST set
#define UM unordered_map
#define MM multimap
#define UMM unordered_multimap
#define MST multiset
#define UST unordered_set
#define UMS unordered_multiset
#define PQ priority_queue
#define Graph V<L<int> >
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

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int a, n , m; cin >> a >> n >> m;
    V<ll> arr(a + 10, 0), brr(a + 10, INT_MAX), crr(a + 10, INT_MAX);
    brr[0] = 0;
    int l, k;
    for(int i = 0; i < n; i++){
        cin >> l >> k;
        while(l < k) arr[l] = 1, l++;
    }
    for(int i = 0; i < m; i++){
        cin >> l >> k;
        crr[l] = crr[l] < k ? crr[l] : k;
    }
    for(int i = 1; i <= a; i++){
        if(arr[i - 1]){
            for(int j = 0; j < i; j++){

                brr[i] = min(brr[i], brr[j] + crr[j] * (i - j));
            }
        }
        else brr[i] = brr[i - 1];
    }
    cout << (brr[a] < 1e9 ? brr[a] : -1) << endl;
    return 0;
}

