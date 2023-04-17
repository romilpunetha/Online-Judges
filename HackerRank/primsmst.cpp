#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

list<pair<int, int> > *g;
int n, m;
ll sum = 0;

void prims(int root) {
    vector<int> dist(n, INT_MAX), visited(n, 0);
    dist[root] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push({ 0, root });
    while (!pq.empty()) {
        pair<int, int> p = pq.top();
        pq.pop();
        if (!visited[p.second]) {
            sum += p.first;
        }
        visited[p.second] = 1;
        for (auto &it : g[p.second]) {
            if (!visited[it.second] && dist[it.second] > it.first) {
                dist[it.second] = it.first;
                pq.push({ it.first, it.second });
            }
        }
    }
    cout << sum << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    g = new list<pair<int, int> >[n];
    for (int i = 0; i < m; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        x--, y--;
        g[x].push_back({ r, y });
        g[y].push_back({ r, x });
    }
    int root;
    cin >> root;
    prims(0);
    return 0;
}
