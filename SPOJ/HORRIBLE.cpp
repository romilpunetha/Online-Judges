#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

long long int *tree, *lazy;
long long int max_size = 0;

void initarr(long long int *a, long long int *b, long long int size) {
    for (long long int i = 0; i < size; i++) {
        a[i] = 0;
        b[i] = 0;
    }
}

void updateRangeUtil(long long int si, long long int ss, long long int se, long long int us, long long int ue, long long int diff) {
    if (lazy[si] != 0) {
        tree[si] += (se - ss + 1) * lazy[si];
        if (ss != se) {
            lazy[si * 2 + 1] += lazy[si];
            lazy[si * 2 + 2] += lazy[si];
        }
        lazy[si] = 0;
    }
    if (ss > se || ss > ue || se < us) {
        return;
    }
    if (ss >= us && se <= ue) {
        tree[si] += (se - ss + 1) * diff;
        if (ss != se) {
            lazy[si * 2 + 1] += diff;
            lazy[si * 2 + 2] += diff;
        }
        return;
    }
    long long int mid = ss + (se - ss) / 2;
    updateRangeUtil(si * 2 + 1, ss, mid, us, ue, diff);
    updateRangeUtil(si * 2 + 2, mid + 1, se, us, ue, diff);
    tree[si] = tree[si * 2 + 1] + tree[si * 2 + 2];
}

void updaterange(long long int n, long long int us, long long int ue, long long int diff) {
    updateRangeUtil(0, 0, n - 1, us, ue, diff);
}

long long int getSumUtil(long long int ss, long long int se, long long int qs, long long int qe, long long int si) {
    if (lazy[si] != 0) {
        tree[si] += (se - ss + 1) * lazy[si];
        if (ss != se) {
            lazy[si * 2 + 1] += lazy[si];
            lazy[si * 2 + 2] += lazy[si];
        }
        lazy[si] = 0;
    }
    if (ss > se || ss > qe || se < qs)
        return 0;
    if (ss >= qs && se <= qe)
        return tree[si];
    long long int mid = ss + (se - ss) / 2;
    return getSumUtil(ss, mid, qs, qe, 2 * si + 1) + getSumUtil(mid + 1, se, qs, qe, 2 * si + 2);
}

long long int getSum(long long int n, long long int qs, long long int qe) {
    if (qs < 0 || qe > n - 1 || qs > qe)
        return -1;
    return getSumUtil(0, n - 1, qs, qe, 0);
}

void constructUtil(long long int arr[], long long int ss, long long int se, long long int *st, long long int si) {
    if (ss > se)
        return;
    if (ss == se) {
        tree[si] = tree[se];
        return;
    }
    long long int mid = ss + (se - ss) / 2;
    constructUtil(arr, ss, mid, st, si * 2 + 1);
    constructUtil(arr, mid + 1, se, st, si * 2 + 2);
    tree[si] = tree[si * 2 + 1] + tree[si * 2 + 2];
}

void constructST(long long int arr[], int n) {
    long long int x = (long long int)(ceil(log2(n)));
    max_size = 2 * (long long int)pow(2, x) - 1;
    tree = new long long int[max_size];
    lazy = new long long int[max_size];
    initarr(tree, lazy, max_size);
    constructUtil(arr, 0, n - 1, tree, 0);
}

int main() {
    int test, N, C;
    cin >> test;
    while (test--) {
        cin >> N >> C;
        long long int *arr = new long long int[N];
        constructST(arr, N);
        int a;
        while (C--) {
            cin >> a;
            switch (a) {
                case 0: {
                    long long int p, q, v;
                    cin >> p >> q >> v;
                    updaterange(N, p - 1, q - 1, v);
                    break;
                }
                case 1: {
                    long long int p, q;
                    cin >> p >> q;
                    cout << getSum(N, p - 1, q - 1) << endl;
                    break;
                }
            }
        }
        delete[] tree;
        delete[] lazy;
    }
    return 0;
}
