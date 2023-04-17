#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
list<int> *g;
vector<int> indeg, tsort, indeg2;
set<int> st;
int n, m, u, v;

int main() {
    scanf(" %d %d", &n, &m);
    indeg.resize(n + 1, 0);
    indeg2.resize(n + 1, 0);
    tsort.resize(n, 0);
    g = new list<int>[n + 1];
    for (int i = 0; i < m; i++) {
        scanf(" %d %d", &u, &v);
        g[u].push_back(v);
        indeg[v]++;
        indeg2[v]++;
    }
    int pos = -1;
    for (auto &it : tsort) cin >> it;
    for (int i = 1; i <= n; i++)
        if (!indeg[i]) st.insert(i);
    int t = st.size();
    if (t > 1) pos = 0;
    for (int i = 0; i < n; i++) {
        st.erase(tsort[i]);
        t--;
        if (t && *st.rbegin() > tsort[i]) pos = i;
        for (auto &it : g[tsort[i]]) {
            indeg[it]--;
            if (!indeg[it]) {
                st.insert(it), t++;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        if (!indeg2[i]) st.insert(i);
    if (pos == -1)
        cout << pos << endl;
    else {
        int rem;
        for (int i = 0; i < n; i++) {
            rem = (i < pos) ? tsort[i] : (i == pos ? *upper_bound(st.begin(), st.end(), tsort[i]) : *st.begin());
            st.erase(rem);
            for (auto &it : g[rem]) {
                indeg2[it]--;
                if (!indeg2[it]) st.insert(it);
            }
            printf("%d ", rem);
        }
    }
    return 0;
}
