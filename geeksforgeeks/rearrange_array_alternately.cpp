#include <bits/stdc++.h>
#define endl '\n'
#define inf INT_MAX
#define pb push_back
#define present(c, x) ((c).find(x) != (c).end())
#define mod 1000000007
#define base 999983
#define baseinv 943912055
#define ff first
#define ss second
#define tr1(x) cerr << #x << ": " << x << endl;
#define tr2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define tr3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define tr4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define tr5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define tr6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (auto &it : arr) cin >> it;
        for (int i = 0; i < n; i++) {
            int temp = arr[i];
            while (temp > 0) {
                int j = i < n / 2 ? 2 * i + 1 : 2 * (n - i - 1);
                if (i == j) {
                    arr[i] = -temp;
                    break;
                }
                if (i != j) {
                    swap(temp, arr[j]);
                    arr[j] = -arr[j];
                    i = j;
                }
            }
        }
        for (auto &it : arr) it = -it;
        for (auto &it : arr) cout << it << " ";
        cout << endl;
    }
    return 0;
}
