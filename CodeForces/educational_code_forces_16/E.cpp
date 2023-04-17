#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
ll n, x, y;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> x >> y;
    vector<ll> arr(n + 10, 1e15);
    arr[1] = x;
    for (int i = 2; i <= n; i++) {
        if (i & 1)
            arr[i] = min(arr[i - 1] + x, arr[(i + 1) >> 1] + y + x);
        else
            arr[i] = min(arr[i - 1] + x, y + arr[i >> 1]);
    }
    cout << arr[n] << endl;
    return 0;
}
