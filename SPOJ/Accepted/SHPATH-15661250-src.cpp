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
#define pp pair<int, int>
#define U_V(x, y) make_pair(x, y)
using namespace std;

typedef vector<vector<pp> > Graph;
struct comp {
    bool operator()(const pp &a, const pp &b) {
        return a.second > b.second;
    }
};

void dijkstra(Graph &cost, unordered_map<string, int> map, string source, string destination) {
    priority_queue<pp, vector<pp>, comp> Q;
    int l = cost.size();
    vector<int> dist(l + 1);
    for (int i = 1; i <= l; i++) {
        dist[i] = INT_MAX;
    }
    dist[map[source]] = 0;
    Q.push(make_pair(map[source], dist[map[source]]));
    while (!Q.empty()) {
        int u = Q.top().first;
        if (u == map[destination]) {
            break;
        }
        Q.pop();
        int len = cost[u].size();
        for (int i = 0; i < len; i++) {
            int v = cost[u][i].first;
            int w = cost[u][i].second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                Q.push(U_V(v, dist[v]));
            }
        }
    }
    cout << dist[map[destination]] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    unordered_map<string, int> map;
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        Graph cost(n + 1);
        for (int i = 1; i <= n; i++) {
            string city_name;
            cin >> city_name;
            map[city_name] = i;
            int neighbours;
            cin >> neighbours;
            for (int j = 0; j < neighbours; j++) {
                int city, weight;
                cin >> city >> weight;
                cost[i].push_back(U_V(city, weight));
            }
        }
        int no_of_tests;
        cin >> no_of_tests;
        while (no_of_tests--) {
            string source, destination;
            cin >> source >> destination;
            dijkstra(cost, map, source, destination);
        }
    }
    return 0;
}
