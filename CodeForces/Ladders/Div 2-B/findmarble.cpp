#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, s, t, curr, i, flag = 0;
    cin >> n >> s >> t;
    s--, t--;
    curr = s;
    vector<int> arr(n);
    for (auto &it : arr) cin >> it, it--;
    for (i = 0; i < n; i++) {
        if (curr == t) {
            flag = 1;
            break;
        }
        curr = arr[curr];
    }
    cout << (flag ? i : -1) << endl;
    return 0;
}
