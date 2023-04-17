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

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<ll> arr(n + 2, 0), pre(n + 2, 0), suf(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    stack<int> st;
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
        if (st.empty())
            pre[i] = -1;
        else
            pre[i] = st.top();
        st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i = n; i >= 1; i--) {
        while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
        if (st.empty())
            suf[i] = -1;
        else
            suf[i] = st.top();
        st.push(i);
    }
    for (int i = 1; i <= n; i++) cout << pre[i] + suf[i] << " ";
    return 0;
}
