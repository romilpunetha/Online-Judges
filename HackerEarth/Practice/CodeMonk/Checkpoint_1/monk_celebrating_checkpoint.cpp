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

int n, x, k;
V<ll> arr;
V<ll> lmax, lmin, rmax, rmin, opt;

void get_lmax(){
    stack<int> st;
    for(int i = n - 1; i >= 0; i--){
        if(st.empty()) st.push(i);
        else{
            while(!st.empty() && arr[i] > arr[st.top()]){
                int k = st.top();
                st.pop();
                lmax[k] = i;
            }
            st.push(i);
        }
    }
    while(!st.empty()) lmax[st.top()] = -1, st.pop();
}

void get_rmax(){
    stack<int> st;
    for(int i = 0; i < n; i++){
        if(st.empty()) st.push(i);
        else{
            while(!st.empty() && arr[i] > arr[st.top()]){
                int k = st.top();
                st.pop();
                rmax[k] = i;
            }
            st.push(i);
        }
    }
    while(!st.empty()) rmax[st.top()] = n, st.pop();
}

void get_lmin(){
    stack<int> st;
    for(int i = n - 1; i >= 0; i--){
        if(st.empty()) st.push(i);
        else{
            while(!st.empty() && arr[i] < arr[st.top()]){
                int k = st.top();
                st.pop();
                lmin[k] = i;
            }
            st.push(i);
        }
    }
    while(!st.empty()) lmin[st.top()] = -1, st.pop();
}

void get_rmin(){
    stack<int> st;
    for(int i = 0; i < n; i++){
        if(st.empty()) st.push(i);
        else{
            while(!st.empty() && arr[i] < arr[st.top()]){
                int k = st.top();
                st.pop();
                rmin[k] = i;
            }
            st.push(i);
        }
    }
    while(!st.empty()) rmin[st.top()] = n, st.pop();
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n >> x >> k;
    arr.resize(n, 0);
    lmax = rmax = lmin = rmin = opt = arr;
    for(int i = 0; i < n; i++) cin >> arr[i];
    get_lmax();
    get_rmax();
    get_lmin();
    get_rmin();
    ll mas = 0, mis = 0;
    for(int i = 0; i < n; i++){
        opt[i] = ((rmax[i] - i) * (i - lmax[i])) - ((rmin[i] - i) * (i - lmin[i]));
        mas += (rmax[i] - i) * (i - lmax[i]) * arr[i];
        mis += (rmin[i] - i) * (i - lmin[i]) * arr[i];
    }
    sort(all(opt), greater<ll>());
    ll sum = mas - mis;
    for(int i = 0; i < x; i++){
        if(opt[i] > 0) sum += opt[i];
    }
    cout << sum << endl;
    return 0;
}

