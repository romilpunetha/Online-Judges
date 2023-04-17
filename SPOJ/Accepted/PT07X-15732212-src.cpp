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

int mvc_maybe(vector<list<int> >& g, vector<bool> visited, int source, vector<int>& dp);
int min(int a, int b) {
    return a < b ? a : b;
}
int mvc_yes(vector<list<int> >& g, vector<bool> visited, int source, vector<int>& dp) {
    visited[source] = true;
    int sum = 1;
    list<int>::iterator i;
    for (i = g[source].begin(); i != g[source].end(); i++) {
        if (!visited[*i])
            sum += mvc_maybe(g, visited, *i, dp);
    }
    return sum;
}
int mvc_no(vector<list<int> >& g, vector<bool> visited, int source, vector<int>& dp) {
    visited[source] = true;
    int sum = 0;
    list<int>::iterator i;
    for (i = g[source].begin(); i != g[source].end(); i++) {
        if (!visited[*i])
            sum += mvc_yes(g, visited, *i, dp);
    }
    return sum;
}

int mvc_maybe(vector<list<int> >& g, vector<bool> visited, int source, vector<int>& dp) {
    if (dp[source] != 0)
        return dp[source];
    dp[source] = min(mvc_yes(g, visited, source, dp), mvc_no(g, visited, source, dp));
    return dp[source];
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
    cout << mvc_maybe(g, visited, 1, dp) << endl;
    return 0;
}
