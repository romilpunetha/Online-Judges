#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int n;
ll pval = 0;

bool bfl(string &n) {
    int flag = 0, cnt = 0;
    for (auto it : n) {
        if (it == '1') cnt++;
        if (!flag && (it != '0' && it != '1')) flag = 1;
    }
    return (cnt <= 1 && !flag);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    string t, s = "a";
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t == "0") {
            cout << 0;
            return 0;
        }
        if (bfl(t))
            pval += t.size() - 1;
        else
            s = t;
    }
    cout << (s == "a" ? "1" : s);
    for (int i = 0; i < pval; i++) cout << 0;
    return 0;
}
