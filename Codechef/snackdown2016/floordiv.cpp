#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test, sum = 0;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        sum = 0;
        while (n--) {
            ll temp;
            cin >> temp;
            sum += temp < 7 ? 1 : (temp < 14 ? 2 : ((int)(log(temp / 14 - 1) / log(6))) % 2 == 0 ? 2
                                                                                                 : 1);
        }
        cout << (sum % 2 == 0 ? "Derek" : "Henry") << endl;
    }
    return 0;
}
