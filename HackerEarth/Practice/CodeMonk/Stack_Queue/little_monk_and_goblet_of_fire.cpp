#include <bits/stdc++.h>
#define endl '\n'
#define inf int_max
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

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<queue<int> > arr(5);
    vector<int> cnt(5, 0);
    queue<int> rank;
    set<int> st;
    while (n--) {
        char c;
        cin >> c;
        if (c == 'E') {
            int x, y;
            cin >> x >> y;
            cnt[x]++;
            arr[x].push(y);
            if (!present(st, x)) rank.push(x), st.insert(x);
        } else {
            cout << rank.front() << " " << arr[rank.front()].front() << endl;
            arr[rank.front()].pop();
            cnt[rank.front()]--;
            if (!cnt[rank.front()]) st.erase(rank.front()), rank.pop();
        }
    }
    return 0;
}
