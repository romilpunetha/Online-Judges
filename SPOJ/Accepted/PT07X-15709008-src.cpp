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
void reduce_degree(unordered_map<int, int>& m, vector<list<int> >& g, vector<int>& visited, int key) {
    visited[key] = 1;
    unordered_map<int, int>::iterator it2;
    list<int>::iterator it;
    // cout<<"source vertex = "<<key<<endl;
    for (it = g[key].begin(); it != g[key].end(); it++) {
        g[*it].remove(key);
        if (visited[*it] == 0) {
            m[*it]--;
            if (m[*it] == 0) {
                visited[*it] = 1;
                m.erase(*it);
            }
            // cout<<"reduced key "<<*it<<" to value "<<m[*it]<<endl;
        }
    }
}

struct greatest {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }
};

int main() {
    int cover = 0;
    ios_base::sync_with_stdio(false);
    int nodes;
    cin >> nodes;
    vector<int> degree(nodes + 1, 0);
    vector<int> visited(nodes + 1, 0);
    vector<list<int> > graph(nodes + 1);
    unordered_map<int, int> m;
    for (int i = 1; i <= nodes - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }
    for (int i = 1; i <= nodes; i++) {
        m.insert(make_pair(i, degree[i]));
    }
    while (!m.empty()) {
        unordered_map<int, int>::iterator it;
        it = min_element(m.begin(), m.end(), greatest());
        // cout<<"node = "<<(*it).first<<" and visited = "<<visited[(*it).first]<<endl;
        if (visited[(*it).first] == 0) {
            visited[(*it).first] = 1;
            int lkey = *(graph[(*it).first].begin());
            m.erase(it);
            m.erase(lkey);
            reduce_degree(m, graph, visited, lkey);
            // cout<<"visited of source = "<<visited[lkey]<<endl;
            cover++;
        } else {
            m.erase(it);
        }
    }
    cout << cover << endl;
    return 0;
}
