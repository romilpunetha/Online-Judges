#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;

bool myfun(const pair<ll, ll>& a, const pair<ll, ll>& b) {
    return a.ff + a.ss > b.ff + b.ss;
}

int n, k;
vector<pair<ll, ll> > arr;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        ll p, q;
        cin >> p >> q;
        arr[i] = { p, q };
    }
    sort(arr.begin(), arr.end(), myfun);
    ll ans = 0;
    for (int i = 0; i < n; i++, k--) {
        ans += k > 0 ? arr[i].ff : -arr[i].ss;
    }
    cout << max(ans, 0LL) << endl;
    return 0;
}
