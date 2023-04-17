#include <cstdio>
using namespace std;
const int mx = 100001, mod = 5000000;
int bit[51][mx];
int n, k;

void update(int *bit, int i, int val) {
    while (i <= mx) {
        bit[i] += val;
        if (bit[i] >= mod) bit[i] -= mod;
        i += i & -i;
    }
}

int query(int *bit, int i) {
    int sum = 0;
    while (i > 0) {
        sum += bit[i];
        if (sum >= mod) sum -= mod;
        i -= i & -i;
    }
    return sum;
}
int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        t++;
        update(bit[1], t, 1);
        for (int j = 2; j <= k; j++) {
            update(bit[j], t, query(bit[j - 1], t - 1));
        }
    }
    printf("%d\n", query(bit[k], 100000));
    return 0;
}
