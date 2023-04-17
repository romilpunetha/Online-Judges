#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    ll len = s.length();
    vector<char> arr(len, '0');
    ll i = 0, j = len - 1, flag = 0;
    while (s[i] == '0') i++;
    s = s.substr(i, len - i + 1);
    len = len - i;
    i = 0, j = len - 1;
    while (i <= j) {
        if (s[i] != s[j]) {
            flag = 1;
            break;
        }
        arr[i] = s[i];
        if (i == j) {
            if ((s[i] - '0') % 2 != 0) {
                flag = 1;
                break;
            } else
                arr[i] = '0' + (s[i] - '0') / 2;
        }
        i++;
        j--;
    }
    if (flag == 1 && s[0] == '1' && len > 1) {
        int cl = 1, cr = 0;
        i = 1, j = len - 1;
        while (1) {
            if (i == j) {
                if ((s[i] - '0') & 1) {
                    arr[1] = '0';
                    break;
                }
                arr[i] = (s[i] - '0') / 2;
            } else if (i == j + 1 && !(cr == 0 && cl == 0)) {
                arr[1] = '0';
                break;
            } else {
                arr[i] = cl == 0 ? '0' : '9';
                arr[j] = '0' + (10 + s[j] - arr[i] - cr) % 10;
            }
            cr = (arr[i] - '0' + arr[j] - '0' + cr) / 10;
            cl = (10 * cl + s[i]) - arr[i] + '0' - arr[j] + '0';
            if (!(cr == 0 || cr == 1)) {
                arr[1] = '0';
                break;
            }
            if (!(cl == 0 || cr == 1)) {
                arr[1] = '0';
                break;
            }
            i++, j--;
        }
    }
    if (!flag)
        for (ll i = 0; i < len; i++) cout << arr[i] - '0';
    else if (len > 1 && arr[1] != '0')
        for (ll i = 1; i < len; i++) cout << arr[i] - '0';
    else
        cout << 0;
    return 0;
}
