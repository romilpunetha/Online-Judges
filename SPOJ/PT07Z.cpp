#include <bits/stdc++.h>

#include <iostream>
#include <list>
#include <vector>
using namespace std;

long int global_max = 0;

long int dijkstra(vector<int> adjacency[], int source, vector<int> visited, int l) {
    long int dist = 0, max1 = 0, max2 = 0, max3 = 0;
    vector<int>::iterator it;
    visited[source] = 1;
    if (adjacency[source].empty()) {
        return 1;
    }
    for (it = adjacency[source].begin(); it != adjacency[source].end(); it++) {
        if (visited[(*it)] != 1) {
            dist = dijkstra(adjacency, (*it), visited, l);
            // visited[(*it)]=0;
            if (dist >= max1) {
                max2 = max1;
                max1 = dist;
            } else if (dist > max2) {
                max2 = dist;
            }
            if (global_max < max1 + max2) {
                global_max = max1 + max2;
            }
            if (max3 < dist) {
                max3 = dist;
            }
        }
    }
    return max3 + 1;
}
int main() {
    long int result = 0;
    int n = 0;
    cin >> n;
    if (n == 0) {
        cout << "0" << endl;
    } else {
        vector<int> adjacency[n + 5];
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            //       scanf("%d %d",&u,&v);
            cin >> u >> v;
            if (u > n || v > n) {
                result = -1;
            } else {
                adjacency[u - 1].push_back(v - 1);
                adjacency[v - 1].push_back(u - 1);
            }
        }
        if (result == -1) {
            cout << "0" << endl;
        } else {
            vector<int> visited(n, -1);
            //        visited[0]=1;
            result = dijkstra(adjacency, 0, visited, n);
            result--;
            if (result < global_max) {
                result = global_max;
            }
            cout << result << endl;
        }
    }
    return 0;
}
