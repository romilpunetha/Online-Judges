#include <limits.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

void vertex_cover(vector<list<int> >& g, int source, int parent, vector<int>& optimal, vector<int>& with, vector<int>& optimal_count, vector<int>& with_count) {
    int with_node = 1, without_node = 0, with_node_count = 1, without_node_count = 1;
    list<int>::iterator it;
    for (it = g[source].begin(); it != g[source].end(); it++) {
        if (*it != parent) {
            vertex_cover(g, *it, source, optimal, with, optimal_count, with_count);
            with_node += optimal[*it];
            with_node_count = (with_node_count * optimal_count[*it]) % 10007;
            without_node += with[*it];
            without_node_count = (without_node_count * with_count[*it]) % 10007;
        }
    }
    with[source] = with_node;
    with_count[source] = with_node_count;
    if (with_node < without_node) {
        optimal[source] = with_node;
        optimal_count[source] = with_node_count;
    } else if (with_node > without_node) {
        optimal[source] = without_node;
        optimal_count[source] = without_node_count;
    } else {
        optimal[source] = without_node;
        optimal_count[source] = (with_node_count + without_node_count) % 10007;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--) {
        int nodes;
        cin >> nodes;
        vector<list<int> > g(nodes + 1);
        vector<int> optimal(nodes + 1, 0);
        vector<int> with(nodes + 1, 0);
        vector<int> optimal_count(nodes + 1, 0);
        vector<int> with_count(nodes + 1, 0);
        int u, v;
        for (int i = 1; i < nodes; i++) {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vertex_cover(g, 1, -1, optimal, with, optimal_count, with_count);
        cout << optimal[1] << " " << optimal_count[1] << endl;
    }

    return 0;
}
