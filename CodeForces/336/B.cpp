#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string pat, txt;
    cin >> pat >> txt;
    int M = pat.length();
    int N = txt.length();
    int pre[N];
    pre[0] = txt[0] == '0';
    for (int i = 0; i < N; i++) {
        pre[i] = pre[i - 1] + (txt[i] == '1');
    }
    ll ans = 0;
    for (int i = 0; i < M; i++) {
        int t = pre[N - M + i] - pre[i - 1];
        ans += pat[i] == '0' ? t : N - M + 1 - t;
    }
    cout << ans << endl;
    return 0;
}
