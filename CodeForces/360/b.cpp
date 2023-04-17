#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string n;
    cin >> n;
    string st = n;
    reverse(n.begin(), n.end());
    cout << st + n << endl;
    return 0;
}
