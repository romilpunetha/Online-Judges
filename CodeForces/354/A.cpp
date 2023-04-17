#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, mn = INT_MAX, posmn = 0, mx = INT_MIN, posmx = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        if (mx < temp) {
            mx = temp;
            posmx = i;
        }
        if (mn > temp) {
            mn = temp;
            posmn = i;
        }
    }
    if (posmx < posmn) swap(posmx, posmn);
    int ans = max(posmx, n - posmn - 1);
    cout << ans;
    return 0;
}
