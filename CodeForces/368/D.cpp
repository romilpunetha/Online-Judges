#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int n, m, q, res = 0;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m >> q;
    vector<vector<bool> > line(q + 1, vector<bool>(m, 0));
    vector<vector<int> > pos(n + 1, vector<bool>(m, 0));
    vector<int> res(q + 1, 0);
    for (int i = 1; i <= q; i++) {
        int ch;
        cin >> ch;
        switch (ch) {
            case 1: {
                int p, q;
                cin >> p >> q;
                line[i] = line[pos[i][p]];
                res[i] = res[i - 1] + (line[i][q] == 0);
                line[i][q] = 1;
                pos[i][p] = i;
                break;
            }
            case 2: {
                int p, q;
                cin >> p >> q;
                line[i] = line[pos[i][p]];
                res[i] = res[i - 1] - (line[i][q] == 1);
                line[i][q] = 0;
                pos[i][p] = i;
                break;
            }
            case 3: {
                int p;
                cin >> p;
                line[i] = line[pos[i][p]];
                for (auto &it : line[i]) res += it == 0, res -= it == 1, it ^= 1;
                pos[i][p] = i;
                break;
            }
            default: {
                int p;
                cin >> p;
                for (int j = 0; j < m; j++) {
                    pos[i][j] = pos[p][j];
                }
                res[i] = res[p];
            }
        }
    }
    return 0;
}
