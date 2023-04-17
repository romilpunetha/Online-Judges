#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, t, size = 0;
    cin >> n;
    multiset<int> st;
    auto it = st.begin();
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c >> t;
        if (c == 'r' && !size)
            cout << "Wrong!\n";
        else
            size--, st.erase(st.find(t));
        if (c == 'a') {
            st.insert(t);
            size++;
        }
    }
    return 0;
}
