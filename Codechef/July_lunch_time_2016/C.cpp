#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
list<int> *g;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
    int N, Q, C, x, y;
    cin >> N;
    g = new list<int>[N];
    vector<int> arr(N, 0);
    for (auto &it : arr) cin >> it;
    for (int i = 0; i < N; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> Q;
    while (Q--) {
        cin >> C >> x >> y;
    }
}
