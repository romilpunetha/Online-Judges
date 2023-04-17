#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
typedef struct coder {
    ll a, b, i;
} coder;
map<ll, ll> mp;
unordered_set<ll> st;
vector<ll> bit;
vector<coder> arr;
int size, i, cnt = 0;

void init() {
    i = 0;
    mp.clear();
    bit.clear();
    bit.resize(1e6 + 10);
    arr.clear();
    arr.resize(size + 1);
}

void update(ll ind, ll val) {
    while (ind <= size) {
        bit[ind] += val;
        ind += ind & -ind;
    }
}

ll query(ll ind) {
    ll sum = 0;
    while (ind > 0) {
        sum += bit[ind];
        ind -= ind & -ind;
    }
    return sum;
}

bool score(const coder &a, const coder &b) {
    return a.a == b.a ? a.b < b.b : a.a < b.a;
}
bool ins(const coder &a, const coder &b) {
    return a.i < b.i;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> size;
    init();
    for (i = 1; i <= size; i++) {
        ll a, b;
        cin >> a >> b;
        arr[i].a = a, arr[i].b = b, arr[i].i = i;
        mp[b] = 1;
    }
    i = 1;
    for (auto &it : mp) it.second = i++;    // map used for value compression
    for (auto &it : arr) it.b = mp[it.b];   // replacing values with compressed values
    sort(arr.begin(), arr.end(), score);    // sorting on first score
    arr.erase(arr.begin());                 // removing 0th element from array
    coder p;
    p.a = 0, p.b = 0, p.i = 0;
    int cnt = 0;
    for (auto &it : arr) {
        if (p.a != 0 && !(p.a == it.a && p.b == it.b)) update(p.b, cnt), cnt = 0;
        p = it;
        cnt++;
        it.a = query(it.b);
    }
    sort(arr.begin(), arr.end(), ins);   // sorting based on position of coder
    for (auto it : arr) cout << it.a << endl;
    return 0;
}
