#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool islucky(int n) {
    while (n) {
        if (n % 10 != 4 && n % 10 != 7)
            return false;
        n = n / 10;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int flag = 0;
    for (int i = 1; i <= n; i++) {
        if (islucky(i) && n % i == 0) {
            flag = 1;
            break;
        }
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
