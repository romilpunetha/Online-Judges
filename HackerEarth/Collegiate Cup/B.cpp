#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int test;
    cin >> test;
    while (test--) {
        ll n, t, i = 0, start = 0, sum = 0, prev = 0, r;
        cin >> n;
        vector<ll> arr(n);
        for (auto &it : arr) cin >> it;
        unordered_set<ll> st;
        while (i < n) {
            while (i < n && st.find(arr[i]) == st.end()) st.insert(arr[i++]);
            t = i - start;
            sum += (t * (t + 1) * (t + 2)) / 6;
            r = max(0ll, prev - start);
            sum -= (r * (r + 1) * (r + 2)) / 6;
            prev = i;
            while (i < n && arr[start] != arr[i]) st.erase(arr[start++]);
            st.erase(arr[start++]);
        }
        cout << sum << endl;
    }
    return 0;
}
