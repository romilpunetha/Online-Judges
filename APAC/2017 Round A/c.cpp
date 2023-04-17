#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;

vector<ll> arr(110);
int n;

ld util(ld r) {
    ld res = 1.0, ans = 0.0;
    for (int i = 0; i < n; i++) {
        ans += arr[n - i] * res;
        res *= (1 + r);
    }
    ans -= arr[0] * res;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    for (int t = 1; t <= test; t++) {
        cin >> n;
        for (int i = 0; i <= n; i++) cin >> arr[i];
        ld l = -1.0, r = 1.0, mid;
        while (r - l >= 1e-9) {
            mid = (l + r) / 2;
            if (util(mid) <= 0)
                r = mid;
            else
                l = mid;
        }
        cout << fixed << setprecision(15) << "Case #" << t << ": " << r << endl;
    }
    return 0;
}
