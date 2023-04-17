#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int n, b, d, a, ans = 0, sum = 0;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> b >> d;
    while (n--) {
        cin >> a;
        if (a <= b) sum += a;
        ans += sum > d;
        sum = sum > d ? 0 : sum;
    }
    cout << ans << endl;
    return 0;
}
