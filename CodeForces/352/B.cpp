#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<char> st(s.begin(), s.end());
    cout << (n = n > 26 ? -1 : n - st.size()) << endl;
    return 0;
}
