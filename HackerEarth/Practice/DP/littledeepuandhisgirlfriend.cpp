#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;
int test, m, n;
int *dp, *arr;
int main() {
    scanf(" %d", &test);
    while (test--) {
        scanf(" %d %d", &m, &n);
        dp = new int[m + 1];
        arr = new int[n];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 0; i < n; i++) scanf(" %d", &arr[i]), dp[arr[i]] = 1;
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j < n; j++) {
                if (i - arr[j] > 0 && !dp[i - arr[j]]) dp[i] = 1;
                if (dp[i]) break;
            }
        }
        if (dp[m])
            printf("Little Deepu\n");
        else
            printf("Kate\n");
    }
    return 0;
}
