#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool myfun(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int mn = INT_MAX, size = 0;
    cin >> size;
    vector<pair<int, int> > m(size);
    for (int i = 0; i < size; i++) {
        int a = 0, b = 0;
        cin >> a >> b;
        m[i] = make_pair(a, b);
    }
    sort(m.begin(), m.end(), myfun);
    for (auto it : m) {
        if (mn == INT_MAX)
            mn = min(it.first, it.second);
        else
            mn = (min(it.first, it.second) >= mn) ? max(mn, min(it.first, it.second)) : max(mn, max(it.first, it.second));
    }
    cout << mn << endl;
    return 0;
}
