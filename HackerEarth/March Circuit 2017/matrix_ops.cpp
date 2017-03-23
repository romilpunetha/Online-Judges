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

int n, m;

bool check(int i, int j){
    return (i >= 0 && i < n && j >= 0 && j < n);
}

typedef struct ptr{
    int i, j, t;
    ptr(){
        i = n - 1;
        j = n - 1;
        t = n - 1;
    }

    bool operator++(){
        i--, j++;
    }
    bool operator--(){
        i++, j--;
    }
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n >> m;
    V<V<ll> >arr(n, V<ll>(n, 1));
    V<V<ll> >visited(n, V<ll>(n, 0));
    ll sum = 0;
    for(int i = 0; i < n; i++) for(int j = 0, t; j < n; j++) cin >> t, sum += t;
    sum -= n * n;
    ptr i, j;
    int t = 1;
    while(sum){
        if(t){
            if(visited[i.i][i.j]) i
        }
        else{

        }
        t++;
        t %= 2;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

