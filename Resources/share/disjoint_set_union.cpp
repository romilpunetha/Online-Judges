#include <bits/stdc++.h>
#define ll long long
using namespace std;
typedef struct node {
    ll int p, r;   // parent,rank
} node;
ll int n;
node a[200010];
void make_set() {
    ll int i;
    for (i = 0; i < n; i++) {
        a[i].p = i;
        a[i].r = 0;
    }
}
ll int find_set(ll int x) {
    if (a[x].p == x)
        return x;
    else {
        a[x].p = find_set(a[x].p);   // Path compression
        return a[x].p;
    }
}
void link_set(ll int x, ll int y) {
    if (a[x].r > a[y].r) {
        a[y].p = x;
    } else if (a[y].r > a[x].r) {
        a[x].p = y;
    } else {
        a[x].p = y;
        a[y].r += 1;
    }
}
void union_set(ll int x, ll int y) {
    ll int i, j;
    i = find_set(x);
    j = find_set(y);
    if (i == j) {
        return;
    } else {
        link_set(i, j);
    }
}
int main() {
    return 0;
}
