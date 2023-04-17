#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int test;
    cin >> test;
    for (int tst = 1; tst <= test; tst++) {
        int n, m;
        cin >> n >> m;
        unordered_set<int> st;
        while (m--) {
            string s;
            cin >> s;
            whats(s);
            if (s == "Flip" || s == "FLIP") {
                int t;
                cin >> t;
                whats(t);
                if (st.find(t) == st.end())
                    st.insert(t);
                else
                    st.erase(t);
            } else {
                st.clear();
            }
            cout << st.size() << endl;
        }
    }
    return 0;
}
