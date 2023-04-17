#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int sum = 0;
    map<int, int> mp;
    for (int i = 0; i < 5; i++) {
        int t;
        cin >> t;
        sum += t;
        mp[t]++;
    }
    int red = 0;
    for (auto it : mp) {
        if (it.second >= 2 && it.first * (it.second >= 3 ? 3 : 2) > red) {
            red = it.first * (it.second >= 3 ? 3 : 2);
        }
    }
    cout << sum - red << endl;
    return 0;
}
