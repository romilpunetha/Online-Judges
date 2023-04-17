#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

bool is_valid(int x, int y) {
    return (x < 8 && x >= 0 && y < 8 && y >= 0);
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    char c;
    int b;
    cin >> c >> b;
    b--;
    int a = c - 'a';
    int ans = 0;
    ans += is_valid(a, b + 1);
    ans += is_valid(a + 1, b + 1);
    ans += is_valid(a + 1, b);
    ans += is_valid(a + 1, b - 1);
    ans += is_valid(a, b - 1);
    ans += is_valid(a - 1, b - 1);
    ans += is_valid(a - 1, b);
    ans += is_valid(a - 1, b + 1);
    cout << ans << endl;
    return 0;
}
