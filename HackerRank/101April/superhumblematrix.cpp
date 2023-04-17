#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1000000007;

int max(int a, int b) {
    return a > b ? a : b;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    if (M < N)
        swap(M, N);
    vector<ll> fact(N + 1, 1);
    for (int i = 2; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    ll sum = 1;
    int l = M == N ? N - 1 : N;
    for (int i = 1; i <= l; i++) {
        sum = ((sum * fact[i]) % mod * fact[i]) % mod;
    }
    for (int i = N * 2 + 1; i < M + N; i++) {
        sum = (sum * fact[N]) % mod;
    }
    if (M == N) {
        sum = (sum * fact[N]) % mod;
    }
    cout << sum << endl;
    return 0;
}
