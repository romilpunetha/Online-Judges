#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;
int n, m, k, test, u, v;
vector<vector<ll> > dist;
vector<ll> w(24);
list<pair<int, vector<ll> > > *g;

void ini() {
    dist.clear();
    dist.resize(24, vector<ll>(n + 1, INT_MAX));
    for (int i = 0; i < 24; i++) dist[i][1] = 0;
}

void dijkstras() {
    for (int i = 0; i < 24; i++) {
        queue<pair<ll, pair<ll, ll> > > pq;
        pq.push({ 0, { 1, i } });
        while (!pq.empty()) {
            pair<ll, pair<ll, ll> > pp = pq.front();
            pq.pop();
            ll s = pp.ss.ff, w = pp.ff, time = (pp.ss.ss) % 24;
            for (auto &it : g[s]) {
                if (dist[i][it.ff] > w + it.ss[time]) {
                    dist[i][it.ff] = w + it.ss[time];
                    pq.push({ dist[i][it.ff], { it.ff, (it.ss[time] + time) % 24 } });
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> test;
    for (int t = 1; t <= test; t++) {
        cin >> n >> m >> k;
        ini();
        g = new list<pair<int, vector<ll> > >[n + 1];
        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            for (auto &it : w) cin >> it;
            g[u].push_back({ v, w });
            g[v].push_back({ u, w });
        }
        cout << "Case #" << t << ": ";
        dijkstras();
        while (k--) {
            int d, time;
            cin >> d >> time;
            cout << (dist[time][d] == INT_MAX ? -1 : dist[time][d]) << " ";
        }
        cout << endl;
    }
    return 0;
}
