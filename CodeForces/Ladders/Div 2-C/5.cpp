#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<ll> arr(100010, 0);
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr[temp] += temp;
    }
    for (int i = 100000; i >= 0; i--) arr[i] += max(arr[i + 2], arr[i + 3]);
    cout << max(arr[1], arr[0]) << endl;
    return 0;
}
