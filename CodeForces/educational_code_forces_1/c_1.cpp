#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<pair<long double, int>> v;
    int n, x, y;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> x >> y, v.push_back({ atan2(y, x) * 180 / 3.14159265359, i + 1 });
    for (auto it : v) cout << it.first << endl;
    for (auto &i : v)
        if (i.first < 0) i.first += 360;
    sort(v.begin(), v.end());
    v.push_back({ v[0].first + 360, v[0].second });
    long double min = 1000, h;
    for (int i = 0; i < n; ++i) {
        h = abs(v[i + 1].first - v[i].first);
        if (h < min) x = v[i].second, y = v[i + 1].second, min = h;
    }
    cout << x << " " << y << endl;
    return 0;
}
