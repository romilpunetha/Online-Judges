#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int mod = 1000000007;
    map<ll, pair<ll, ll> > m;
    m[LONG_MIN] = m[LONG_MAX] = make_pair(0, 0);   // the fist one for the height of the tree, the second for the index at which node x will be present
    int len;
    cin >> len;
    for (int i = 0; i < len; i++) {
        ll temp;
        cin >> temp;
        auto l = m.lower_bound(temp);
        auto r = l--;
        auto s = (l->second).first >= (r->second).first ? l : r;   // comparing which height is shorter
        m[temp] = make_pair((s->second).first + 1, (((s->second).second << 1) % mod + (s->first > temp ? 0 : 1)) % mod);
        cout << (m[temp].second) % mod << " ";
    }
    return 0;
}
