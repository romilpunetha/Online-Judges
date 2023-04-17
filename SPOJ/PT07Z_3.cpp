#include <bits/stdc++.h>

#include <iostream>
#include <list>
#include <vector>
using namespace std;

int global_max = 0;

int dfs(vector<int> adjacency[], int source, vector<int> visited) {
    int dist = 0, max1 = 0, max2 = 0, max3 = 0;
    visited[source] = 1;
    for (int i = 0; i < adjacency[source].size(); i++) {
        if (visited[adjacency[source][i]] != 1) {
            dist = dfs(adjacency, adjacency[source][i], visited);
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
    int result = 0;
    int n, a, b;
    cin >> n;
    vector<int> v[n + 9];
    for (int i = 0; i < n - 1; i++) {
        scanf("%d%d", &a, &b);
        v[a - 1].push_back(b - 1);
        v[b - 1].push_back(a - 1);
    }
    vector<int> visited(n, 0);
    result = dfs(v, 0, visited);
    result--;
    if (result > global_max) {
        global_max = result;
    }
    cout << global_max << endl;
    return 0;
}
