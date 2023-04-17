#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, lim;
    cin >> n >> lim;
    vector<pair<int, int> > arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end());
    ll fship = 0, i = 0, start = 0, mx = 0;
    while (start < n) {
        while (i < n && arr[i].first - arr[start].first < lim) fship += arr[i].second, i++;
        mx = max(mx, fship);
        fship -= arr[start++].second;
    }
    cout << mx << endl;
    return 0;
}
