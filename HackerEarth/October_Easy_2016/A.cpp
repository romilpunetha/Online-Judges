#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;

struct C {
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
        if (a.ff == b.ff) return a.ss < b.ss;
        return a.ff > b.ff;
    }
};

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, t, q;
    cin >> n >> t;
    string name;
    set<pair<int, string>, C> st;
    while (n--) {
        cin >> name >> q;
        st.insert({ q, name });
    }
    auto it = st.begin();
    while (t--) {
        cout << it->ss << endl;
        it++;
    }
    return 0;
}
