#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void mover(vector<vector<pair<int, int> > >& arr, int r, int col) {
    pair<int, int> temp = arr[r][0];
    for (int i = 0; i < col - 1; i++) {
        arr[r][i] = arr[r][i + 1];
    }
    arr[r][col - 1] = temp;
}

void movec(vector<vector<pair<int, int> > >& arr, int c, int row) {
    pair<int, int> temp = arr[0][c];
    for (int i = 0; i < row - 1; i++) {
        arr[i][c] = arr[i + 1][c];
    }
    arr[row - 1][c] = temp;
}

void getans(vector<vector<int> >& ans, vector<vector<pair<int, int> > >& arr, int r, int c, int v) {
    int row = arr[r][c].first, col = arr[r][c].second;
    ans[row][col] = v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<pair<int, int> > > arr(n, vector<pair<int, int> >(m));
    vector<vector<int> > ans(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = make_pair(i, j);
        }
    }
    while (q--) {
        int t;
        cin >> t;
        switch (t) {
            case 1: {
                int r;
                cin >> r;
                mover(arr, r - 1, m);
                break;
            }
            case 2: {
                int c;
                cin >> c;
                movec(arr, c - 1, n);
                break;
            }
            case 3: {
                int r, c, v;
                cin >> r >> c >> v;
                getans(ans, arr, r - 1, c - 1, v);
                break;
            }
        }
    }
    for (auto it : ans) {
        for (auto jt : it) {
            cout << jt << " ";
        }
        cout << endl;
    }
    return 0;
}
