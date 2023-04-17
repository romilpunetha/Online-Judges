#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int k;
string s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k >> s;
    int len = s.length();
    ll ans = 0;
    for (int i = 0; i < len; i++) {
        int j = i;
        unordered_set<char> st;
        while (j < len && st.size() <= k) st.insert(s[j++]), ans += st.size() == k;
    }
    cout << ans << endl;
    return 0;
}
