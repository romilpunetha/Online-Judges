#include <stdio.h>
#define mod 1000000007
inline void read(int &x) {
    x = 0;
    char c = getchar_unlocked();
    for (; c < '0' || c > '9'; c = getchar_unlocked())
        ;
    for (; c >= '0' && c <= '9'; c = getchar_unlocked())
        x = (x << 3) + (x << 1) + (c - '0');
}
inline void write(int x) {
    char buffor[35];
    int i = 0;
    do {
        buffor[i++] = (x % 10) + '0';
        x /= 10;
    } while (x);
    i--;
    while (i >= 0) putchar_unlocked(buffor[i--]);
    putchar_unlocked('\n');
}
int dp[100005][1025];
int main() {
    int t, n, p, res, l, i, j;
    char s[15];
    read(t);
    while (t--) {
        read(n);
        for (j = 0; j <= 1024; j++) {
            dp[0][j] = 0;
        }
        dp[0][0] = 1;
        gets(s);
        p = 1;
        res = 0;
        for (i = 9; i >= 0; i--) {
            if (s[i] == 'w') {
                res += p;
            }
            p *= 2;
        }
        for (i = 1; i <= n; i++) {
            gets(s);
            p = 1;
            l = 0;
            for (j = 9; j >= 0; j--) {
                if (s[j] == '+') {
                    l += p;
                }
                p *= 2;
            }
            // int g=i%2;
            // int h=(i+1)%2;
            int a = l;
            for (j = 0; j < 1024; j++) {
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j ^ a]);
                if (dp[i][j] >= mod) {
                    dp[i][j] = dp[i][j] % mod;
                }
            }
        }
        write(dp[n][res]);
    }
    return 0;
}
