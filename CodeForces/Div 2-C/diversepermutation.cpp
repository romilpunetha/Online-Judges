#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 1; i <= n; i++) arr[i - 1] = i;
    int start = 0, end = k, i = 1;
    while (start <= end) cout << ((i++) % 2 ? arr[start++] : arr[end--]) << " ";
    start = k + 1;
    while (start < n) cout << arr[start++] << " ";
    cout << endl;
    return 0;
}
