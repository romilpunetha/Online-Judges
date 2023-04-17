#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<char, int> mp;
map<int, int> mp2;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    while (test--) {
        mp.clear();
        mp2.clear();
        string s;
        cin >> s;
        int k;
        cin >> k;
        int len = s.length(), j = 0, res = INT_MAX, sum = 0, temp = 0;
        vector<int> arr(26, 0);
        for (int i = 0; i < len; i++) {
            mp[s[i]]++;
        }
        for (auto &it : mp) arr[j++] = it.second;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < 26; i++) {
            if (!arr[i]) continue;
            temp += (i - 1 >= 0) ? arr[i - 1] : 0;
            sum = temp;
            for (j = i + 1; j < 26; j++) {
                if (!arr[j]) continue;
                if (arr[j] - arr[i] > k) sum += arr[j] - arr[i] - k;
            }
            res = min(res, sum);
        }
        cout << res << endl;
    }
    return 0;
}
