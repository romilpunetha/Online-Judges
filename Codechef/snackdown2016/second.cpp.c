#include <stdio.h>
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        long long int a[n], i = 0;
        long long int skipsum = 0, nonskipsum = 0, maxsum = 0, maxnum = -9999999999999;
        for (i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            if (maxnum < a[i])
                maxnum = a[i];
            if (a[i] < 0) {
                if (skipsum + a[i] < 0)
                    skipsum = 0;
                else
                    skipsum += a[i];
                skipsum = skipsum > nonskipsum ? skipsum : nonskipsum;
                if (nonskipsum + a[i] < 0)
                    nonskipsum = 0;
                else
                    nonskipsum += a[i];
            } else {
                skipsum += a[i];
                nonskipsum += a[i];
            }
            long long int max = skipsum > nonskipsum ? skipsum : nonskipsum;
            if (maxsum < max)
                maxsum = max;
        }
        if (maxsum == 0)
            maxsum = maxnum;
        printf("%lld\n", maxsum);
    }
    return 0;
}
