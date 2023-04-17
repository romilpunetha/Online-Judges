#include <bits/stdc++.h>
#define endl '\n'
#define inf INT_MAX
#define pb push_back
#define present(c, x) ((c).find(x) != (c).end())
#define base 999983
#define baseinv 943912055
#define ff first
#define ss second
#define tr1(x) cerr << #x << ": " << x << endl;
#define tr2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define tr3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define tr4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define tr5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define tr6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

int mx = (2e5 + 10) * 40, t = 0;
vector<vector<int> > arr(mx, vector<int>(2, -1));
vector<int> cnt(mx, 0);

void insert(int num) {
    int p = 0;
    for (int i = 31; i >= 0; i--) {
        if (arr[p][num >> i & 1] == -1) arr[p][num >> i & 1] = ++t;
        p = arr[p][num >> i & 1], cnt[p]++;
    }
}

void erase(int num) {
    int p = 0;
    for (int i = 31; i >= 0; i--) {
        p = arr[p][num >> i & 1];
        cnt[p]--;
    }
}

int query(int num) {
    int p = 0, res = 0;
    for (int i = 31; i >= 0; i--) {
        if (arr[p][(num >> i & 1) ^ 1] != -1 && cnt[arr[p][(num >> i & 1) ^ 1]])
            res += (1 << i), p = arr[p][(num >> i & 1) ^ 1];
        else
            p = arr[p][num >> i & 1];
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    int pre = 0, res = 0, res2 = 0;
    insert(0);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        arr[i] = t;
        pre ^= t;
        insert(pre);
        if (query(pre ^ x) > res) tr2(i, query(pre ^ x));
        res = max(res, query(pre ^ x));
    }
    for (int i = 0; i < n; i++) {
        int t = 0;
        for (int j = i; j < n; j++) {
            t ^= arr[j];
            t ^= x;
            res2 = max(res2, t);
            t ^= x;
        }
    }
    tr2(res, res2);
    return 0;
}
