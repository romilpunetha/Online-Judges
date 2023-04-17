#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, test;
    cin >> n >> test;
    vector<int> arr(n);
    unordered_set<int> st;
    for (int i = 0; i < n; i++) cin >> arr[i];
    st.insert(arr[n - 1]);
    arr[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (st.find(arr[i]) == st.end()) {
            st.insert(arr[i]);
            arr[i] = arr[i + 1] + 1;
        } else
            arr[i] = arr[i + 1];
    }
    while (test--) {
        int t;
        cin >> t;
        t--;
        cout << arr[t] << endl;
    }
    return 0;
}
