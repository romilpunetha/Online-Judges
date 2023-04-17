#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int size, d;
    cin >> size >> d;
    vector<int> arr(size);
    unordered_map<int, int> m;
    for (int i = 0; i < size; i++) {
        int temp;
        cin >> temp;
        m[temp]++;
    }
    int counts = 0;
    for (auto it : m) {
        if (m.find((it.first) + d) != m.end() && m.find((it.first) + d + d) != m.end()) {
            counts++;
        }
    }
    cout << counts << endl;
    return 0;
}
