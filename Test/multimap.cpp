#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    multimap<int, int> mp;
    mp.insert(make_pair(4, 6));
    mp.insert(make_pair(4, 1));
    mp.insert(make_pair(4, 2));
    mp.insert(make_pair(4, 3));
    mp.insert(make_pair(9, 9));
    // mp.erase(mp.find(4));
    for (auto it : mp) {
        for (auto jt = it.first; jt != it.second; jt++) {
            cout << jt << endl;
        }
    }
    return 0;
}
