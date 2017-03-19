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

bool C(const P<int, int>&a, const P<int, int> &b){
    return a.ss < b.ss;
}

void merge_sort(V<P<int, int> >&arr, int st, int en){
    if(st >= en) return;
    int mid = (st + en) / 2;
    merge_sort(arr, st, mid);
    merge_sort(arr, mid + 1, en);
    V<P<int, int> > brr(en - st + 1);
    int k = 0, val = 0, i = st, j = mid + 1;
    while(i <= mid && j <= en){
        if(arr[i].ff + val >= arr[j].ff){
            brr[k++] = arr[j++];
            val++;
        }
        else{
            brr[k++] = {arr[i].ff + val, arr[i].ss};
            i++;
        }
    }
    while(i <= mid) brr[k++] = {arr[i].ff + val, arr[i].ss}, i++;
    while(j <= en) brr[k++] = arr[j++];
    for(int i = 0; i <= en - st; i++) arr[st + i] = brr[i];
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n; cin >> n; V<P<int, int> >arr(n);
    for(int i = 0; i < n; i++){ int t; cin >> t; arr[i] = {t, i}; }
    merge_sort(arr, 0, n - 1);
    sort(all(arr), C);
    for( auto &it : arr ) cout << it.ff << " ";
    return 0;
}

