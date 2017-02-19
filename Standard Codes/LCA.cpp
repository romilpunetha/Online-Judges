ll maxn = 1e6, ln = 20;
vector<vector<int> > pa(ln, vector<int>(maxn, -1));

void dfs(node* root, int parent, int depth){
    root -> level = depth;
    pa[0][root -> id] = parent;
    for(auto &it : root -> child){
        dfs(it, root -> id, depth + 1);
    }
}

ll lca(ll u, ll v){
    if(tree[u] -> level < tree[v]-> level) swap(u, v);
    for(int i = ln - 1; i >= 0; i--){
        if(tree[u] -> level - (1 << i) >= tree[v] -> level){
            u = pa[i][u];
        }
    }
    for(int i = ln - 1; i >= 0; i--){
        if(pa[i][u] != -1 && pa[i][u] != pa[i][v]){
            u = pa[i][u];
            v = pa[i][v];
        }
    }
    return pa[0][u];
}

for(int i = 1; i < ln; i++){
    for(int j = 0; j < n; j++){
        if(pa[i - 1][j] != -1){
            pa[i][j] = pa[i - 1][pa[i - 1][j]];
        }
    }
}

