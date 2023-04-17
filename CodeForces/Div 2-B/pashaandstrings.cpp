#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int task;
    cin >> task;
    int len = s.length();
    vector<int> arr(len, 0);
    while (task--) {
        int temp;
        cin >> temp;
        temp--;
        arr[temp] = (arr[temp] + 1) % 2;
    }
    for (int i = 1; i < len / 2; i++) {
        arr[i] = (arr[i] + arr[i - 1]) % 2;
    }
    for (int i = 0; i < len / 2; i++) {
        if (arr[i]) swap(s[i], s[len - i - 1]);
    }
    cout << s << endl;
    return 0;
}
