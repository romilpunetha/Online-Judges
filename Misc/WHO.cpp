#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    double sum = 0;
    int t, n;
    cin >> n >> t;
    vector<ll> arr(n), alloc(n);
    for (int i = 0; i < n; i++) cin >> arr[i], sum += arr[i];
    sum = ceil((sum * 1.0) / t);
    ll mx = 0;
    for (int i = 0; i < n; i++) {
        alloc[i] = arr[i] / sum;
        if (alloc[i] > t) alloc[i] = t;
        if (!alloc[i]) alloc[i] = 1;
        t -= alloc[i];
        mx = max(mx, arr[i] / alloc[i]);
    }
    cout << mx << endl;
    return 0;
}
