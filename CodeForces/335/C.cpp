#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int arr[n + 1] = { 0 }, m = 0;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        m = max(m, arr[t] = arr[t - 1] + 1);
    }
    cout << n - m << endl;
    return 0;
}
