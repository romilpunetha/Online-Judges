#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    if (s.length() & 1) return cout << -1, 0;
    vector<int> arr(50, 0);
    int i = 0;
    while (s[i]) arr[s[i] - 'A']++, i++;
    int ans = (abs(arr['L' - 'A'] - arr['R' - 'A'])) % 2;
    ans += abs(arr['L' - 'A'] - arr['R' - 'A']) / 2 + abs(arr['U' - 'A'] - arr['D' - 'A']) / 2;
    cout << ans;
    return 0;
}
