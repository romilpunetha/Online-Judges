#include <bits/stdc++.h>
#define tr1(x) cerr << #x << ":\t" << x << endl
#define tr2(x, y) cerr << #x << ":\t" << x << "\t|\t" << #y << ":\t" << y << endl
#define tr3(x, y, z) cerr << #x << ":\t" << x << "\t|\t" << #y << ":\t" << y << "\t|\t" << #z << ":\t" << z << endl
#define tr4(a, b, c, d) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << endl
#define tr5(a, b, c, d, e) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << "\t|\t" << #e << ":\t" << e << endl
#define tr6(a, b, c, d, e, f) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << "\t|\t" << #e << ":\t" << e << "\t|\t" << #f << ":\t" << f << endl
#define m 1000000009
#define base 999983
#define ff first
#define ss second
using namespace std;
typedef unsigned long long ll;
string s1, s2;
int s, e, mid, l1, l2;
vector<ll> hash1(250010, 0), hash2(250010, 0), power(250010, 1);
pair<int, int> ans = { -1, -1 };

void ini() {
    hash1[0] = s1[0], hash2[0] = s2[0];
    for (int i = 1; i < l1; i++) {
        hash1[i] = hash1[i - 1] * base + s1[i];
    }
    for (int i = 1; i < l2; i++) {
        hash2[i] = hash2[i - 1] * base + s2[i];
    }
    for (int i = 1; i <= 250005; i++) {
        power[i] = power[i - 1] * base;
    }
}

bool is_valid() {
    unordered_map<ll, pair<int, int> > mp;
    ll h = hash1[mid - 1];
    mp[h] = { 0, mid - 1 };
    for (int i = 1; i + mid <= l1; i++) {
        h = hash1[i + mid - 1] - hash1[i - 1] * power[mid];
        mp[h] = { i, i + mid - 1 };
    }

    h = hash2[mid - 1];
    if (mp.find(h) != mp.end()) {
        ans = mp[h];
        return 1;
    }
    for (int i = 1; i + mid <= l2; i++) {
        h = hash2[i + mid - 1] - hash2[i - 1] * power[mid];
        if (mp.find(h) != mp.end()) {
            ans = mp[h];
            return 1;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> s1 >> s2;
    l1 = s1.length(), l2 = s2.length(), s = 1, e = l2;
    ini();
    while (s < e) {
        mid = s + ((e - s) >> 1);
        if (is_valid())
            s = mid + 1;
        else
            e = mid;
    }
    mid = s;
    is_valid();
    if (ans.ff == -1)
        cout << "0" << endl;
    else {
        cout << s1.substr(ans.ff, ans.ss - ans.ff + 1) << endl;
        cout << ans.ss - ans.ff + 1 << endl;
    }
    return 0;
}
