#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int mx = (2e5 + 10) * 40, t = 0;
vector<vector<int> > arr(mx, vector<int>(2, -1));
vector<int> cnt(mx, 0);

void insert(int num) {
    int p = 0;
    for (int i = 30; i >= 0; i--) {
        if (arr[p][num >> i & 1] == -1) arr[p][num >> i & 1] = ++t;
        p = arr[p][num >> i & 1], cnt[p]++;
    }
}

void erase(int num) {
    int p = 0;
    for (int i = 30; i >= 0; i--) {
        p = arr[p][num >> i & 1];
        cnt[p]--;
    }
}

int query(int num) {
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i--) {
        if (arr[p][(num >> i & 1) ^ 1] != -1 && cnt[arr[p][(num >> i & 1) ^ 1]])
            res += (1 << i), p = arr[p][(num >> i & 1) ^ 1];
        else
            p = arr[p][num >> i & 1];
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    insert(0);
    int n;
    cin >> n;
    while (n--) {
        char c;
        int t;
        cin >> c >> t;
        if (c == '+') insert(t);
        if (c == '-') erase(t);
        if (c == '?') cout << query(t) << endl;
    }
    return 0;
}
