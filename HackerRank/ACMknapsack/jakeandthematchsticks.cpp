#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1000000007;

void display(vector<vector<ll> > &arr) {
    cout << "array : " << endl;
    int l = arr.size();
    int b = arr[0].size();
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < b; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    vector<ll> arr(N);
    vector<vector<ll> > dp(N, vector<ll>(K, 0));
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        arr[i] %= K;
    }
    dp[0][arr[0] % K]++;
    // display(dp);
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < K; j++) {
            if (dp[i - 1][j] != 0) {
                // cout<<"index = "<<(arr[i]+j)%K<<endl;
                dp[i][(arr[i] + j) % K] = (dp[i][(arr[i] + j) % K] + dp[i - 1][j]) % mod;
            }
        }
        for (int j = 0; j < K; j++) {
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
        }
        dp[i][arr[i] % K]++;
        dp[i][arr[i] % K] %= mod;
        // display(dp);
    }
    cout << dp[N - 1][0] % mod << endl;
    return 0;
}
