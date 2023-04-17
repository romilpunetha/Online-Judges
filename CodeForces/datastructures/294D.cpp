#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int n;
ll ans = 0;
vector<int> arr(26);
string s;
ll pre = 0;
map<ll, int> mp[26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 26; i++) cin >> arr[i];
    cin >> s;
    int len = s.length();
    for (int i = 0; i < len; i++) {
        ans += mp[s[i] - 'a'][pre];
        pre += arr[s[i] - 'a'];
        mp[s[i] - 'a'][pre]++;
    }
    cout << ans << endl;
    return 0;
}
