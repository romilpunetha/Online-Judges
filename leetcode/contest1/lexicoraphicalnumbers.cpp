#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int lim, k = 0;
void util(int num, vector<int> &arr) {
    if (num > lim) return;
    arr[k++] = num;
    num *= 10;
    for (int i = 0; i < 10; i++) {
        if (num + i <= lim)
            util(num + i, arr);
        else
            return;
    }
}
vector<int> lexicalOrder(int n) {
    vector<int> arr(n);
    lim = n;
    for (int i = 1; i < 10; i++) util(i, arr);
    return arr;
}
int main() {
    int n;
    cin >> n;
    vector<int> arr = lexicalOrder(n);
    for (auto &it : arr) cout << it << " ";
    cout << endl;
    return 0;
}
