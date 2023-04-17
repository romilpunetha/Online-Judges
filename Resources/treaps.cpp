// educational codeforces 15 tshirt
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

typedef long long ll;
typedef long double ld;

using namespace std;

mt19937 rnd(100);
const int MX = 1e7;

struct node {
    node *l, *r;
    int sz;
    int x;
    int d;
    node() {
        l = r = 0;
        sz = x = d = 0;
    }
};

void upd(node *v) {
    v->sz = 1 + (v->l ? v->l->sz : 0) + (v->r ? v->r->sz : 0);
}

node mem[MX + 100000];
int us[MX + 100000];
int ndcnt;

node *newnode() {
    return &mem[ndcnt++];
}

node *push(node *v) {
    if (!v)
        return v;
    node *v2 = newnode();
    *v2 = *v;
    if (!v->d)
        return v2;
    v2->d = 0;
    if (v2->l) {
        v2->l = newnode();
        *(v2->l) = *(v->l);
        v2->l->d += v->d;
        v2->l->x += v->d;
    }
    if (v2->r) {
        v2->r = newnode();
        *(v2->r) = *(v->r);
        v2->r->d += v->d;
        v2->r->x += v->d;
    }
    return v2;
}

node *merge(node *l, node *r) {
    if (!l)
        return r;
    if (!r)
        return l;
    if ((ll)(rnd() % (l->sz + r->sz)) < l->sz) {
        l = push(l);
        l->r = merge(l->r, r);
        upd(l);
        return l;
    } else {
        r = push(r);
        r->l = merge(l, r->l);
        upd(r);
        return r;
    }
}

void split(node *v, int k, node *&l, node *&r) {
    if (!v) {
        l = r = 0;
        return;
    }
    v = push(v);
    if ((v->l ? v->l->sz : 0) >= k) {
        split(v->l, k, l, v->l);
        upd(v);
        r = v;
    } else {
        split(v->r, k - (v->l ? v->l->sz : 0) - 1, v->r, r);
        upd(v);
        l = v;
    }
}

int get(node *v, int x) {
    int szl = (v->l ? v->l->sz : 0);
    if (szl > x)
        return v->d + get(v->l, x);
    if (szl == x)
        return v->x;
    return v->d + get(v->r, x - szl - 1);
}

int n;
pair<int, int> a[220000];
node *root;

vector<node> vv;

void dfs(int v) {
    if (us[v] != -1)
        return;
    us[v] = vv.size();
    vv.push_back(mem[v]);
    if (mem[v].l) {
        dfs(mem[v].l - mem);
        vv[us[v]].l = mem + us[mem[v].l - mem];
    }
    if (mem[v].r) {
        dfs(mem[v].r - mem);
        vv[us[v]].r = mem + us[mem[v].r - mem];
    }
}

void rebuild() {
    vv.clear();
    fill(us, us + MX + 100000, -1);
    int st = root - mem;
    dfs(st);
    st = us[st];
    for (int i = 0; i < (int)vv.size(); ++i)
        mem[i] = vv[i];
    ndcnt = vv.size();
    root = mem + st;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &a[i].second, &a[i].first), a[i].first = -a[i].first;
    sort(a, a + n);
    for (int i = 0; i < 30; ++i) {
        node *tmp = newnode();
        tmp->l = root;
        tmp->r = root;
        upd(tmp);
        root = tmp;
    }
    int mmx = 0;
    for (int i = n - 1; i >= 0; --i) {
        int got = ndcnt;
        int x = a[i].second;
        int sz = root->sz;
        node *l1, *r1;
        split(root, x, l1, r1);
        node *l2, *r2;
        split(root, sz - x, l2, r2);
        if (l2) {
            node *tmp = newnode();
            *tmp = *l2;
            l2 = tmp;
            l2->d += 1, l2->x += 1;
        }
        root = merge(l1, l2);
        mmx = max(mmx, ndcnt - got);
        if (ndcnt > MX) {
            rebuild();
        }
    }
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        int b;
        scanf("%d", &b);
        printf("%d ", get(root, b));
    }
    printf("\n");
    cerr << ndcnt << "\n";
    cerr << sizeof(node) << "\n";
    cerr << mmx << "\n";
    return 0;
}
