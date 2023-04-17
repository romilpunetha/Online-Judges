#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    while (test--) {
        int prev = 0, cnt = 0;
        int n;
        cin >> n;
        vector<ll> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++) {
            ll temp;
            cin >> temp;
            if (arr[i] - prev >= temp) cnt++;
            prev = arr[i];
        }
        cout << cnt << endl;
    }
    return 0;
}
