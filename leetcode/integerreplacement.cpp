#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int util(int n, int cnt) {
    if (n == 1) return cnt;
    if (n & 1)
        return min(util(n + 1, cnt + 1), util(n - 1, cnt + 1));
    else
        return util(n >> 1, cnt + 1);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    cout << util(n, 0) << endl;
    return 0;
}
