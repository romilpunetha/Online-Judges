#include <bits/stdc++.h>
#define endl '\n'
#define inf INT_MAX
#define pb push_back
#define der(c, x) ((c).find(x) != (c).end())
#define base 999983
#define baseinv 943912055
#define ff first
#define ss second
#define V vector
#define L list
#define P pair
#define MP map
#define ST set
#define UM unordered_map
#define MM multimap
#define UMM unordered_multimap
#define MST multiset
#define UST unordered_set
#define UMS unordered_multiset
#define PQ priority_queue
#define Graph V<L<int> >
#define all(a) (a).begin(), (a).end()
#define tr1(x) cerr << #x << ": " << x << endl;
#define tr2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define tr3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define tr4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define tr5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define tr6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
using namespace std;
template <typename A, typename B>
inline ostream& operator<<(ostream& os, const pair<A, B>& v) { return os << v.first << ' ' << v.second; }
template <typename A>
inline ostream& operator<<(ostream& os, const vector<A>& v) {
    auto it = v.begin();
    os << *it;
    for (++it; it != v.end(); os << ' ' << *it++)
        ;
    return os;
}
void tr() { cout << endl; }
template <typename H, typename... T>
inline void tr(H head, T... tail) {
    cerr << head << ' ';
    tr(tail...);
}
typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ldbl;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    V<int> arr[3];
    for (int i = 0; i < 3; i++) arr[i] = V<int>(2e6 + 10, -1);
    MST<int> st;
    for (int i = 0; i < n; i++) {
        cin >> arr[0][i];
        st.insert(arr[0][i]);
        auto it = st.lower_bound(arr[0][i]);
        it++;
        if (it != st.end()) {
            arr[2][i] = *it;
            st.erase(it);
        }
        arr[1][i] = st.size();
    }
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            cin >> arr[0][n];
            st.insert(arr[0][n]);
            auto it = st.lower_bound(arr[0][n]);
            it++;
            if (it != st.end()) {
                arr[2][n] = *it;
                st.erase(it);
            }
            arr[1][n] = st.size();
            n++;
            cout << st.size() << endl;
        } else {
            n--;
            st.erase(st.find(arr[0][n]));
            if (arr[2][n] != -1) st.insert(arr[2][n]);
            arr[2][n] = -1;
            arr[1][n] = st.size();
            cout << arr[1][n] << endl;
        }
    }
    return 0;
}
