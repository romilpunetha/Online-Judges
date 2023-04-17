#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;

unordered_map<ll, bool> mp;
int cnt = 0;
bool util(ll num) {
    if (cnt > 20) return 0;
    if (num == 1 || num == 4) return 1;
    cnt++;
    if (mp.find(num) != mp.end()) return mp[num];
    ll sum = 0;
    num *= num;
    while (num) {
        sum += num % 10;
        num /= 10;
    }
    if (sum < 10)
        mp[num] = (sum == 1 || sum == 4);
    else
        mp[num] = util(sum);
    return mp[num];
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int test;
    cin >> test;
    while (test--) {
        ll num;
        cin >> num;
        cnt = 0;
        if (util(num))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
