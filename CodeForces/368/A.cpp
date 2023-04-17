#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int n, m, flag = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n * m; i++) {
        char c;
        cin >> c;
        flag = flag | (c == 'C' || c == 'M' || c == 'Y');
    }
    if (flag)
        cout << "#Color\n";
    else
        cout << "#Black&White\n";
    return 0;
}
