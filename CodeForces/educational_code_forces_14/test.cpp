#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    set<char> st;
    int i = 0;
    while (s[i]) st.insert(s[i++]);
    for (auto &it : st) cout << it << " ";
    cout << endl;
    return 0;
}
