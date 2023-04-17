#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;
vector<int> util(vector<int> &A) {
    int c = 0, n = 1, j = 0, i = A.size() - 1;
    vector<int> res(i + 1), res2;
    while (i >= 0) {
        res[i] = (A[i] + c + n) % 10;
        c = (A[i] + c + n) / 10;
        n = 0;
        i--;
    }
    if (c) res.insert(res.begin(), c);
    while (!res[j]) j++;
    for (; j < res.size(); j++) res2.push_back(res[j]);
    return res2;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int test;
    cin >> test;
    while (test--) {
        ll d;
        cin >> d;
        vector<int> arr;
        while (d) {
            if (d < 10)
                arr.push_back(d), d = 0;
            else
                arr.push_back(9), d -= 9;
        }
        reverse(arr.begin(), arr.end());
        vector<int> res = util(arr);
        ll ans = 0;
        for (auto &it : res) ans += it;
        cout << ans << endl;
    }
    return 0;
}
