#include <iostream>
#include <vector>
using namespace std;

long long int max(long long int a, long long int b) {
    return a > b ? a : b;
}

long long int bs(vector<long long int>& arr, long long int a, long long int b) {
    int flag = 0;
    if (b == a)
        return 0;
    long long int i = 0;
    for (i = a; i <= b; i++) {
        if (a > 0) {
            if (arr[i] - arr[a - 1] == arr[b] - arr[i]) {
                flag = 1;
                break;
            }
        } else {
            if (arr[i] == arr[b] - arr[i]) {
                flag = 1;
                break;
            }
        }
    }
    if (!flag)
        return 0;
    else {
        return 1 + max(bs(arr, a, i), bs(arr, i + 1, b));
    }
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        long long int n, points = 0;
        cin >> n;
        long long int temp = 0;
        vector<long long int> arr(n);
        for (long long int i = 0; i < n; i++) {
            cin >> temp;
            if (i == 0)
                arr[i] = temp;
            else
                arr[i] = arr[i - 1] + temp;
        }
        points = bs(arr, 0, n - 1);
        cout << points << endl;
    }
    return 0;
}
