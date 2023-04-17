#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    long long int sum = 0;
    vector<long long int> arr(n, 0);
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr[i] = temp;
    }
    sort(arr.begin(), arr.end());
    int pos = 0, i = 1;
    while (pos < n) {
        if (arr[pos] <= i * i) {
            sum += i * i - arr[pos];
            pos++;
        } else
            sum += i * i;
        i++;
    }
    cout << sum << endl;
    return 0;
}
