#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int a, b, c;
    cin >> a >> b >> c;
    while (a || b || c) {
        if (2 * b == a + c)
            cout << "AP " << 2 * c - b << endl;
        else if (b * b == a * c)
            cout << "GP " << (c * c) / b << endl;
        cin >> a >> b >> c;
    }
    return 0;
}
