#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void move(vector<int>& arr, int x, int n) {
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) arr[i] = i + 1;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            move(arr, x, n);
        } else {
        }
    }
    return 0;
}
