#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<vector<double> > arr(n, vector<double>(n + 1, 0.0));
    vector<double> x(n, 0.0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n; j++) cin >> arr[i][j];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i][i] < arr[j][i]) swap(arr[i], arr[j]);
        }
    }
    cout << "After Pivotisation" << endl;
    for (auto it : arr) {
        for (auto jt : it) cout << jt << " ";
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double t = arr[j][i] / arr[i][i];
            for (int k = 0; k <= n; k++) arr[j][k] -= t * arr[i][k];
        }
    }
    cout << "After Elimination" << endl;
    for (auto it : arr) {
        for (auto jt : it) cout << jt << " ";
        cout << endl;
    }
    cout << endl;
    for (int i = n - 1; i >= 0; i--) {
        x[i] = arr[i][n];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                x[i] -= arr[i][j] * x[j];
            }
        }
        x[i] /= arr[i][i];
    }
    for (auto it : x) cout << it << " ";
    cout << endl;
    return 0;
}
