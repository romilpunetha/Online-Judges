
#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int test;
    cin >> test;
    for (int t = 1; t <= test; t++) {
        ll n, sum = 0;
        cin >> n;
        vector<pair<ll, ll> > x(2 * n);
        vector<ll> ans(n + 1, 0);
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            x[2 * i] = { a, -(i + 1) };
            x[2 * i + 1] = { b, i + 1 };
        }
        int active = 0, start = 0, sst = 0;
        unordered_set<ll> st;
        sort(x.begin(), x.end());
        for (auto it : x) cout << it.first << " " << it.second << endl;
        for (int i = 0; i < 2 * n; i++) {
            if (x[i].second < 0) {
                active++;
                if (active == 1)
                    start = i, sst = i;
                else if (active == 2)
                    ans[*st.begin()] += x[i].first - x[start].first - !(abs(x[start].second) == abs(*st.begin()));
                st.insert(-x[i].second);
            } else {
                active--;
                if (!active) {
                    sum += x[i].first - x[sst].first + 1;
                    ans[*st.begin()] += x[i].first - x[start].first;
                    if (abs(x[i].second) == abs(x[start].second)) ans[*st.begin()]++;
                } else if (active == 1)
                    start = i;
                st.erase(x[i].second);
            }
        }
        for (auto it : ans) cout << it << " ";
        cout << endl;
        cout << "Case #" << t << ": " << sum - *max_element(ans.begin(), ans.end()) << endl;
    }
    return 0;
}
