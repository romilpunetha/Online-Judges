#include <bits/stdc++.h>
using namespace std;
long double pi = 3.14159265359;
int main() {
    int n;
    cin >> n;
    vector<pair<long double, int> > arr(n);
    for (int i = 0; i < n; i++) {
        long double x, y;
        cin >> x >> y;
        arr[i] = { atan2(y, x) * 180.0 / pi, i };
        if (arr[i].first < 0) arr[i].first += 360.0;
    }
    sort(arr.begin(), arr.end());
    arr.push_back({ arr[0].first + 360.0, arr[0].second });
    int a = 0, b = 0;
    long double res = 1000.0, diff = 0.0;
    for (int i = 0; i < n; i++) {
        diff = arr[i + 1].first - arr[i].first;
        if (diff < res) a = arr[i].second, b = arr[i + 1].second, res = diff;
    }
    cout << a + 1 << " " << b + 1 << endl;
    return 0;
}
