typedef struct Dsu {
    vector<ll> p, size, count;

    Dsu(int n){
        p.resize(n + 1);
        size.resize(n + 1);
        count.resize(n + 1);
    }

    int get(int x) {
        return x == p[x]? x : (p[x] = get(p[x]));
    }

    void merge(int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            p[x] = y;
            size[y] += size[x];
            count[y] += count[x] + 1;
        } else
            count[y]++;
    }
}Dsu;
