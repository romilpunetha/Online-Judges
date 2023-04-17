#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int ans = 0;
int dign = 1, digm = 1;
vector<int> arr1, arr2;
vector<bool> vis(7, 0);
void util2(int pos, bool t) {
    if (pos == digm) {
        ans++;
        return;
    }
    for (int i = 0; i <= (t ? arr2[pos] : 6); i++) {
        if (!vis[i]) {
            vis[i] = 1;
            util2(pos + 1, t & (i == arr2[pos]));
            vis[i] = 0;
        }
    }
}

void util(int pos, bool t) {
    if (pos == dign) {
        util2(0, 1);
        return;
    }
    for (int i = 0; i <= (t ? arr1[pos] : 6); i++) {
        if (!vis[i]) {
            vis[i] = 1;
            util(pos + 1, t & (i == arr1[pos]));
            vis[i] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    int maxn = n - 1, maxm = m - 1;
    arr1.push_back(maxn % 7);
    arr2.push_back(maxm % 7);
    while (maxn > 6) {
        dign++;
        maxn /= 7;
        arr1.push_back(maxn % 7);
    }
    while (maxm > 6) {
        digm++;
        maxm /= 7;
        arr2.push_back(maxm % 7);
    }
    if (dign + digm > 7) {
        cout << 0 << endl;
        return 0;
    }
    // whats(dign);whats(digm);
    reverse(arr1.begin(), arr1.end());
    reverse(arr2.begin(), arr2.end());
    util(0, 1);
    cout << ans << endl;
    return 0;
}
