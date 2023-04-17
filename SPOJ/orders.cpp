#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
vector<int> bit;
int size;

void init() {
    bit.clear();
    bit.resize(1e7 + 10, 0);
}

void update(int ind, int val) {
    while (ind <= size) {
        bit[ind] += val;
        ind += ind & -ind;
    }
}

int query(int ind) {
    int sum = 0;
    while (ind > 0) {
        sum += bit[ind];
        ind -= ind & -ind;
    }
    return sum;
}

int bs(int start, int end, int key) {
    while (start < end) {
        int mid = start + ((end - start) >> 1);
        if (query(mid) >= key)
            end = mid;
        else
            start = mid + 1;
    }
    return start;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    for (cin >> test; test--;) {
        init();
        cin >> size;
        vector<int> arr(size, 0);
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
            update(i + 1, 1);
        }
        for (int i = size - 1; i >= 0; i--) {
            int t = bs(1, size, i - arr[i] + 1);
            update(t, -1);
            arr[i] = t;
        }
        for (auto it : arr) cout << it << " ";
        cout << endl;
    }
    return 0;
}
