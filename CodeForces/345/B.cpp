#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    multimap<int, int> mp;
    int len;
    cin >> len;
    map<int, int> mp2;
    for (int i = 0; i < len; i++) {
        int temp;
        cin >> temp;
        mp2[temp]++;
    }
    for (auto it : mp2) {
        mp.insert(make_pair(it.second, it.first));
    }
    int cnt = 0, val = 0;
    len = mp2.size();
    while (mp.size() > 0) {
        cnt += (mp.begin()->first - val) * (len - 1);
        val += (mp.begin()->first - val);
        len -= mp.count(mp.begin()->first);
        mp.erase(mp.begin()->first);
    }
    cout << cnt << endl;
    return 0;
}
