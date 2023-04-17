#include <limits.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;
long long int merge(vector<long long int>& arr, long long int i, long long int k, long long int j) {
    long long int inv = 0;
    vector<long long int> c(j - i + 1);
    long long int ptr = 0;
    long long int left = i;
    long long int right = k + 1;
    while (left <= k && right <= j) {
        if (arr[left] <= arr[right]) {
            c[ptr] = arr[left];
            ptr++;
            left++;
        } else {
            c[ptr] = arr[right];
            ptr++;
            right++;
            inv = inv + k - left + 1;
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
    for (long long int p = 0; p < ptr; p++) {
        arr[i + p] = c[p];
    }
    return inv;
}

long long int mergesort(vector<long long int>& arr, long long int i, long long int j) {
    // cout<<"i = "<<i<<" and j = "<<j<<endl;
    // long long int dummy;
    // cin>>dummy;
    if (j - i <= 0) {
        return 0;
    } else {
        long long int k = i + ((j - i) / 2);
        // cout<<"calling mergesort with "<<i<<" "<<k<<endl;
        long long int left = mergesort(arr, i, k);
        // cout<<"calling mergesort with "<<k+1<<" "<<j<<endl;
        long long int right = mergesort(arr, k + 1, j);
        // cout<<"calling merge with "<<i<<" "<<k<<" "<<j<<endl;
        long long int inv = merge(arr, i, k, j);
        return inv + left + right;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--) {
        int count1 = 0;
        int size;
        cin >> size;
        cin.ignore(INT_MAX, '\n');
        map<string, int> m;
        vector<long long int> arr(size, 0);
        for (int i = 1; i <= size; i++) {
            string s;
            cin >> s;
            m[s] = i;
        }
        for (int i = 0; i < size; i++) {
            string s;
            cin >> s;
            arr[i] = m[s];
        }
        count1 = mergesort(arr, 0, size - 1);
        cout << count1 << endl;
    }
    return 0;
}
