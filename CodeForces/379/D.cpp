#include <bits/stdc++.h>
#define tr1(x) cerr << #x << ":\t" << x << endl
#define tr2(x, y) cerr << #x << ":\t" << x << "\t|\t" << #y << ":\t" << y << endl
#define tr3(x, y, z) cerr << #x << ":\t" << x << "\t|\t" << #y << ":\t" << y << "\t|\t" << #z << ":\t" << z << endl
#define tr4(a, b, c, d) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << endl
#define tr5(a, b, c, d, e) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << "\t|\t" << #e << ":\t" << e << endl
#define tr6(a, b, c, d, e, f) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << "\t|\t" << #e << ":\t" << e << "\t|\t" << #f << ":\t" << f << endl
#define base 999983
#define baseinv 943912055
#define ff first
#define ss second
using namespace std;
typedef long long ll;
int n, x0, y0;
unordered_map<int, pair<char, pair<int, int> > > mp;

int get_dir1(int x, int y) {
    int p = x - x0, q = y - y0;
    if (abs(p) != abs(q)) return -1;
    if (p > 0 && q > 0) return 2;
    if (p > 0 && q < 0) return 4;
    if (p < 0 && q < 0) return 6;
    if (p < 0 && q > 0) return 8;
    return -1;
}

int get_dir2(int x, int y) {
    if (x == x0) {
        if (y > y0)
            return 1;
        else
            return 5;
    } else if (y == y0) {
        if (x < x0)
            return 7;
        else
            return 3;
    }
    return -1;
}

ll dist(ll x, ll y) {
    return (x0 - x) * (x0 - x) + (y0 - y) * (y0 - y);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> x0 >> y0;
    while (n--) {
        char c;
        int p, q;
        cin >> c >> p >> q;
        ll d1 = dist(p, q);
        int dir1 = get_dir1(p, q);
        int dir2 = get_dir2(p, q);
        if (dir1 == -1 && dir2 == -1) continue;
        if (dir1 != -1) {
            if (mp.find(dir1) == mp.end())
                mp[dir1] = { c, { p, q } };
            else {
                ll d2 = dist(mp[dir1].ss.ff, mp[dir1].ss.ss);
                if (d1 < d2) mp[dir1] = { c, { p, q } };
            }
        }
        if (dir2 != -1) {
            if (mp.find(dir2) == mp.end())
                mp[dir2] = { c, { p, q } };
            else {
                ll d2 = dist(mp[dir2].ss.ff, mp[dir2].ss.ss);
                if (d1 < d2) mp[dir2] = { c, { p, q } };
            }
        }
    }
    int ans = 0;
    for (auto &it : mp) {
        if (it.ss.ff == 'Q') {
            ans = 1;
            break;
        }
        if (it.ff == 1 || it.ff == 3 || it.ff == 5 || it.ff == 7) {
            if (it.ss.ff == 'R') {
                ans = 1;
                break;
            }
        }
        if (it.ff == 2 || it.ff == 4 || it.ff == 6 || it.ff == 8) {
            if (it.ss.ff == 'B') {
                ans = 1;
                break;
            }
        }
    }
    if (ans)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
