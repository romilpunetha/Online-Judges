#include <bits/stdc++.h>
#define ff first
#define ss second
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
unordered_set<int> st;
set<pair<int, pair<int, int> > > st1, st2;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int test;
    cin >> test;
    for (int tst = 1; tst <= test; tst++) {
        int n, mx = 0, mn = 0;
        cin >> n;
        vector<pair<int, pair<int, int> > > arr(n);
        st.clear();
        st1.clear();
        st2.clear();
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            arr[i] = { i, { a, b } };
            st1.insert({ a, { b, i } });
            st2.insert({ b, { a, i } });
            st.insert(i);
        }
        bool flag = 1, flag2 = 0;
        while (st.size() > 1 && flag) {
            pair<int, pair<int, int> > p = *st1.rbegin(), q = *st2.rbegin();
            mx = p.ff, mn = q.ff;
            for (auto &it : arr)
                if (st.find(it.ff) != st.end() && it.ss.ff == p.ff && it.ss.ss == q.ff) {
                    flag2 = 1;
                    break;
                }
            if (flag2) break;
            for (auto &it : arr) {
                if (st.find(it.ff) != st.end() && it.ss.ff != p.ff && it.ss.ss != q.ff) {
                    flag = 1;
                    break;
                } else
                    flag = 0;
            }
            while (!st1.empty() && p.ff == mx) {
                st1.erase(p);
                st2.erase(st2.find({ p.ss.ff, { p.ff, p.ss.ss } }));
                st.erase(p.ss.ss);
                if (st1.empty()) break;
                p = *st1.rbegin();
            }
            while (!st2.empty() && q.ff == mn) {
                st2.erase(q);
                st1.erase(st1.find({ q.ss.ff, { q.ff, q.ss.ss } }));
                st.erase(q.ss.ss);
                if (st2.empty()) break;
                q = *st2.rbegin();
            }
        }
        flag = flag & st.size();
        cout << "Case #" << tst << ": ";
        if (flag || flag2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
