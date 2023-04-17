#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int util(vector<int>& arr, int size) {
    int ans = 0;
    for (int i = 0; i < size; i++) {
        if (i) ans = max(ans, arr[i] ^ arr[i - 1]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int size;
    cin >> size;
    vector<int> arr(size);
    map<pair<int, int>, int> m;
    int ans = INT_MAX;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    do {
        ans = min(ans, util(arr, size));
    } while (next_permutation(arr.begin(), arr.end()));
    cout << ans << endl;
    return 0;
}
