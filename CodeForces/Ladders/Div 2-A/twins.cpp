#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int size;
    cin >> size;
    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < size; i++) {
        if (i != 0)
            arr[i] += arr[i - 1];
    }
    int cnt = 0, sum = 0;
    for (int i = size - 1; i >= 0; i--) {
        if (sum > arr[i])
            break;
        sum += arr[i] - arr[i - 1];
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
