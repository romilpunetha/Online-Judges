#include <bits/stdc++.h>
using namespace std;
int merge(vector<int>& arr, int i, int k, int j) {
    int inv = 0;
    vector<int> c(j - i + 1);
    int ptr = 0;
    int left = i;
    int right = k + 1;
    while (left <= k && right <= j) {
        if (arr[left] <= arr[right]) {
            c[ptr] = arr[left];
            ptr++;
            left++;
        } else {
            c[ptr] = arr[right];
            inv += (__gcd(arr[left], arr[right]) == 1);
            ptr++;
            right++;
        }
    }
    while (left <= k) {
        c[ptr] = arr[left];
        ptr++;
        left++;
    }
    while (right <= j) {
        c[ptr] = arr[right];
        ptr++;
        right++;
    }
    for (int p = 0; p < ptr; p++) {
        arr[i + p] = c[p];
    }
    return inv;
}

int mergesort(vector<int>& arr, int i, int j) {
    if (j - i <= 0) {
        return 0;
    } else {
        int k = i + ((j - i) >> 1);
        int left = mergesort(arr, i, k);
        int right = mergesort(arr, k + 1, j);
        int inv = merge(arr, i, k, j);
        return inv + left + right;
    }
}

int main() {
    int count1 = 0;
    int size;
    cin >> size;
    vector<int> arr(size, 0);
    for (int i = 0; i < size; i++) cin >> arr[i];
    count1 = mergesort(arr, 0, size - 1);
    cout << count1 << endl;
    return 0;
}
