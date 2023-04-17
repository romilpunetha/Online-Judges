#include <bits/stdc++.h>
#define tr1(x) cerr << #x << ":\t" << x << endl
#define tr2(x, y) cerr << #x << ":\t" << x << "\t|\t" << #y << ":\t" << y << endl
#define tr3(x, y, z) cerr << #x << ":\t" << x << "\t|\t" << #y << ":\t" << y << "\t|\t" << #z << ":\t" << z << endl
#define tr4(a, b, c, d) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << endl
#define tr5(a, b, c, d, e) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << "\t|\t" << #e << ":\t" << e << endl
#define tr6(a, b, c, d, e, f) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << "\t|\t" << #e << ":\t" << e << "\t|\t" << #f << ":\t" << f << endl
#define ff first
#define ss second
using namespace std;
typedef long long ll;

int x[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int y[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int n, m, k;
vector<vector<int> > arr;
bool check(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m) return 0;
    if (arr[i][j] == -1) return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int test;
    cin >> test;
    for (int tt = 1; tt <= test; tt++) {
        cout << "Scenario #" << tt << ":\n";
        cin >> n >> m >> k;
        arr = vector<vector<int> >(n, vector<int>(m, 0));
        while (k--) {
            int p, q;
            cin >> p >> q;
            arr[p][q] = -1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == -1) continue;
                for (int k = 0; k < 8; k++) {
                    arr[i][j] += check(i + x[k], j + y[k]);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == -1)
                    cout << "*";
                else if (arr[i][j] == 0)
                    cout << "-";
                else
                    cout << arr[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}
