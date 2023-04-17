#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int arr[26];
string s;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    for (int i = 0; i < 26; i++) cin >> arr[i];
    cin >> s;
    int len = s.length(), mx = 0;
    for (auto &it : s) mx = max(mx, arr[it - 'a']);
    cout << mx * len << endl;
    return 0;
}
