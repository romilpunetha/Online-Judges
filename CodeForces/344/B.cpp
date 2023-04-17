#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int> > arr(n, vector<int>(m, 0));
    vector<pair<int, int> > row(n, make_pair(INT_MAX, -1)), col(m, make_pair(INT_MAX, -1));
    while (k--) {
        int c, rc, val;
        cin >> c >> rc >> val;
        if (c == 1)
            row[rc - 1] = make_pair(k, val);
        else
            col[rc - 1] = make_pair(k, val);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (row[i].second == -1 && col[j].second == -1)
                cout << "0 ";
            else if (row[i].first < col[j].first)
                cout << row[i].second << " ";
            else
                cout << col[j].second << " ";
        }
        cout << endl;
    }
    return 0;
}
