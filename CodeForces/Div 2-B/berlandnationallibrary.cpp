#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, mx = 0, cnt = 0;
    cin >> n;
    unordered_set<int> enter;
    for (int i = 0; i < n; i++) {
        char a;
        int b;
        cin >> a >> b;
        switch (a) {
            case '+': {
                cnt++;
                enter.insert(b);
                mx = max(mx, cnt);
                break;
            }
            case '-': {
                if (enter.find(b) == enter.end())
                    mx++;
                else
                    cnt--;
                break;
            }
        }
    }
    cout << mx << endl;
    return 0;
}
