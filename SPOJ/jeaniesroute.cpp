#include <iostream>
#include <list>
#include <vector>
#define mp make_pair
using namespace std;

typedef vector<list<pair<int, int> > > graph;

void find_relevant(graph &g, vector<int> &relevant, vector<int> &visited, int parent) {
    if (visited[parent])
        return;
    visited[parent] = 1;
    list<int>::iterator it;
    for (it = g[parent].begin(); it != g[parent].end(); it++) {
        if (!visited[it->first]) {
        }
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    graph g(N + 1);
    vector<int> relevant(N + 1, 0);
    vector<int> visited(N + 1, 0);
    vector<int> dest(N + 1, 0);
    for (int i = 0; i < K; i++) {
        int t;
        cin >> t;
        dest[t] = 1;
        relevant[t] = 1;
    }
    for (int i = 0; i < N - 1; i++) {
        int p, q, r;
        cin >> p >> q >> r;
        g[p].push_back(mp(q, r));
        g[q].push_back(mp(p, r));
    }
    visited[dest[0]] = 1;
    find_relevant(g, relevant, visited, dest[0]);
    return 0;
}
