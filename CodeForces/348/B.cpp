#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int find(int x, vector<int> &parent) {
    if (parent[x] == x) return x;
    return find(parent[x], parent);
}

bool unions(int &x, int &y, vector<int> &parent) {
    int px = find(x, parent);
    int py = find(y, parent);
    if (px == py) return false;
    x = y;
    parent[py] = px;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int len;
    cin >> len;
    string s;
    cin >> s;
    vector<int> arr(len), parent(len, -1);
    for (int i = 0; i < len; i++) cin >> arr[i], arr[i] = s[i] == '>' ? arr[i] : -arr[i], parent[i] = i;
    int i = 0, next = 0;
    do {
        next = i + arr[i];
    } while (next >= 0 && next < len && unions(i, next, parent));
    cout << ((next < 0 || next >= len) ? "FINITE" : "INFINITE") << endl;
    return 0;
}
