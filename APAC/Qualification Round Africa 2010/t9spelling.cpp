#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

pair<int, int> s[] = { { 2, 1 }, { 2, 2 }, { 2, 3 }, { 3, 1 }, { 3, 2 }, { 3, 3 }, { 4, 1 }, { 4, 2 }, { 4, 3 }, { 5, 1 }, { 5, 2 }, { 5, 3 }, { 6, 1 }, { 6, 2 }, { 6, 3 }, { 7, 1 }, { 7, 2 }, { 7, 3 }, { 7, 4 }, { 8, 1 }, { 8, 2 }, { 8, 3 }, { 9, 1 }, { 9, 2 }, { 9, 3 }, { 9, 4 }, { 0, 1 } };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, num, rep;
    cin >> t;
    cin.ignore();
    for (int test = 1; test <= t; test++) {
        string st;
        getline(cin, st);
        int prev = -1;
        cout << "Case #" << test << ": ";
        for (auto &it : st) {
            if (it == ' ') {
                num = s[26].first;
                rep = s[26].second;
            } else {
                num = s[it - 'a'].first;
                rep = s[it - 'a'].second;
            }
            if (num == prev) cout << " ";
            for (int i = 0; i < rep; i++) cout << num;
            prev = num;
        }
        cout << endl;
    }
    return 0;
}
