#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, start = 1, sum = 0;
    cin >> n >> k;
    vector<vector<int> > arr(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k - 1; j++) {
            arr[i][j] = start++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = k - 1; j < n; j++) {
            arr[i][j] = start++;
        }
    }
    for (int i = 0; i < n; i++) sum += arr[i][k - 1];
    cout << sum << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
