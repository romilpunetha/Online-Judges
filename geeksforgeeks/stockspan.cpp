#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;

using namespace std;

int main() {
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        vector<int> arr(n), res(n, 1);
        stack<int> st;
        for (auto &it : arr) cin >> it;
        res[0] = 1;
        st.push(0);
        for (int i = 1; i < n; i++) {
            while (!st.empty() && arr[i] <= arr[st.top()]) {
                res[i] += res[st.top()];
                st.pop();
            }
            st.push(i);
        }
        for (auto &it : res) cout << it << " ";
        cout << endl;
    }
    return 0;
}
