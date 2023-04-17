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

int min(int a, int b) {
    return a < b ? a : b;
}

int vertex_cover(vector<list<int> >& g, vector<bool> visited, int source, vector<int>& dp) {
    if (!visited[source]) {
        visited[source] = true;
        if (dp[source] != 0) {
            return dp[source];
        }
        int size_inc = 1;
        int size_exc = 0;
        list<int>::iterator it, i;
        for (it = g[source].begin(); it != g[source].end(); it++) {
            if (!visited[*it]) {
                size_inc += vertex_cover(g, visited, *it, dp);
                size_exc += 1;
                visited[*it] = true;
                for (i = g[*it].begin(); i != g[*it].end(); i++) {
                    size_exc += vertex_cover(g, visited, *i, dp);
                }
            }
        }
        dp[source] = min(size_inc, size_exc);
        return dp[source];
    } else {
        return 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int nodes = 0;
    cin >> nodes;
    vector<list<int> > g(nodes + 1);
    vector<int> dp(nodes + 1, 0);
    vector<bool> visited(nodes + 1, false);
    for (int i = 1; i < nodes; i++) {
        int u, v;
        cin >> u >> v;
        // cout<<"u = "<<u<<" v = "<<v<<endl;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout << vertex_cover(g, visited, 1, dp) << endl;
    return 0;
}
