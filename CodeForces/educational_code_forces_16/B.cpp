#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
ll n, ans = LLONG_MAX, ind = 0, sum = 0;
vector<ll> arr;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) sum += abs(arr[i] - arr[0]);
    n--;
    ans = sum;
    for (int i = 1; i <= n; i++) {
        sum = sum - (n - i) * (arr[i] - arr[i - 1]) + (i - 1) * (arr[i] - arr[i - 1]);
        if (ans > sum) ans = sum, ind = i;
    }
    cout << arr[ind] << endl;
    return 0;
}
