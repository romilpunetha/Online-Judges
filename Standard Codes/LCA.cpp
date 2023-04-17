ll maxn = 1e6, ln = 20;
vector<vector<int> > pa(ln, vector<int>(maxn, -1));

void dfs(int root, int parent, int depth) {
    level[root] = depth;
    pa[0][root] = parent;
    for (auto &it : g[root]) {
        dfs(it, root, depth + 1);
    }
}

int lca(int u, int v) {
    if (level[u] < level[v]) swap(u, v);
    int d = level[u] - level[v];
    for (int i = 0; i <= ln; i++) {
        if ((1 << i) & d) u = pa[i][u];
    }
    if (u == v) return u;
    for (int i = ln - 1; i >= 0; i--) {
        if (pa[i][u] != -1 && pa[i][u] != pa[i][v]) {
            u = pa[i][u];
            v = pa[i][v];
        }
    }
    return pa[0][u];
}

for (int i = 1; i < ln; i++) {
    for (int j = 0; j < n; j++) {
        if (pa[i - 1][j] != -1) {
            pa[i][j] = pa[i - 1][pa[i - 1][j]];
        }
    }
}
