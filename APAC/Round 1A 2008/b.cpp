#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int no, cust, p, r, s, result;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    for (int t = 1; t <= test; t++) {
        cout << "Case #" << t << ":";
        int M, N;
        cin >> N >> M;
        vector<int> malted(M, -1), options(M, 0), done(M, 0), ans(N, 0);
        vector<vector<bool> > choice(M, vector<bool>(N, false));
        for (int i = 0; i < M; i++) {
            int T;
            cin >> T;
            options[i] = T;
            for (int p = 0; p < T; p++) {
                int X, Y;
                cin >> X >> Y;
                X--;
                if (Y == 1)
                    malted[i] = X, options[i]--;
                else
                    choice[i][X] = 1;
            }
        }
        bool flag = 0, flag2 = 0;
        while (true) {
            flag = 0, flag2 = 0;
            for (int i = 0; i < M; i++) {
                if (!done[i] && !options[i]) {
                    if (malted[i] == -1) {
                        flag = true;
                        break;
                    } else {
                        done[i] = true;
                        options[i]--, ans[malted[i]] = 1;
                    }
                    flag2 = 1;
                }
            }
            if (flag || !flag2) break;
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    if (choice[i][j] && ans[j]) choice[i][j] = false, options[i]--;
                }
            }
        }
        if (flag)
            cout << " IMPOSSIBLE";
        else
            for (auto &it : ans) cout << " " << it;
        cout << endl;
    }
    return 0;
}
