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

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    freopen("team.in", "r", stdin);
    freopen("team.out", "w", stdout);
    vector<vector<int> > arr(3, vector<int>(3));
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) cin >> arr[i][j];
    double ans = 0.0;
    ans = max(ans, sqrt(arr[0][0] * arr[0][0] + arr[1][1] * arr[1][1] + arr[2][2] * arr[2][2]));
    ans = max(ans, sqrt(arr[0][0] * arr[0][0] + arr[1][2] * arr[1][2] + arr[2][1] * arr[2][1]));
    ans = max(ans, sqrt(arr[0][1] * arr[0][1] + arr[1][0] * arr[1][0] + arr[2][2] * arr[2][2]));
    ans = max(ans, sqrt(arr[0][1] * arr[0][1] + arr[1][2] * arr[1][2] + arr[2][0] * arr[2][0]));
    ans = max(ans, sqrt(arr[0][2] * arr[0][2] + arr[1][0] * arr[1][0] + arr[2][1] * arr[2][1]));
    ans = max(ans, sqrt(arr[0][2] * arr[0][2] + arr[1][1] * arr[1][1] + arr[2][0] * arr[2][0]));
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}
