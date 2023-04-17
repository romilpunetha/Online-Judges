#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, s, ans = 0;
    cin >> n >> s;
    vector<pair<int, int> > arr(n);
    for (int i = 0; i < n; i++) {
        int f, t;
        cin >> f >> t;
        arr[i] = { f, t };
    }
    sort(arr.begin(), arr.end(), [](pair<int, int> &a, pair<int, int> &b) { return a.first > b.first; });
    for (int i = 0; i < n; i++) {
        ans += s - arr[i].first;
        if (arr[i].second > ans) ans = arr[i].second;
        s = arr[i].first;
    }
    ans += s;
    cout << ans << endl;
    return 0;
}
