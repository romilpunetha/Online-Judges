#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

vector<int> bit(1e6, 0), arr(1e6);
int n, q, t, a, b;

void update(int i, int val) {
    while (i < 1e6) {
        bit[i] += val;
        i += i & -i;
    }
}

int query(int i) {
    int sum = 0;
    while (i) {
        sum += bit[i];
        i -= i & -i;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (!arr[i]) update(i + 1, 1);
    }
    while (q--) {
        cin >> t;
        if (t == 1) {
            cin >> a;
            if (query(999999) < a)
                cout << "NO\n";
            else {
                int s = 1, e = n;
                while (s < e) {
                    int m = s + ((e - s) >> 1);
                    if (query(m) >= a)
                        e = m;
                    else
                        s = m + 1;
                }
                cout << --s << endl;
            }
        } else {
            cin >> a >> b;
            if (arr[a] == 0 && b)
                update(a + 1, -1);
            else if (arr[a] && !b)
                update(a + 1, 1);
            arr[a] = b;
        }
    }
    return 0;
}
