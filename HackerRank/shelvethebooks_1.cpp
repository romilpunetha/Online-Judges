#include <stdio.h>
#include <stdlib.h>

unsigned long long fact(int n) {
    unsigned long long int f = 1;
    int i;
    for (i = 2; i <= n; i++) {
        f = (f * i) % 1000000007;
    }
    return f;
}
unsigned long long int pw(int k) {
    unsigned long long int p = 1;
    int i;
    for (i = 0; i < k; i++) {
        p = (p * 8) % 1000000007;
    }
    return p;
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, k;
        scanf("%d %d", &n, &k);
        unsigned long long int ans;
        printf("pow = %llu\n", pw(k));
        ans = pw(k);
        ans = (ans * fact(k)) % 1000000007;
        // printf("%llu\n",ans);
    }
    return 0;
}
