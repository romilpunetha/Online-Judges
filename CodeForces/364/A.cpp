#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<int> arr(n);
    int sum = 0;
    for (auto &it : arr) cin >> it, sum += it;
    sum /= (n >> 1);
    for (int i = 0; i < n; i++) {
        for (int j = n; j > i; j--) {
            if (arr[i] + arr[j] == sum) {
                cout << i + 1 << " " << j + 1 << endl;
                arr[j] = -1;
                arr[i] = -1;
                break;
            }
        }
    }
    return 0;
}
