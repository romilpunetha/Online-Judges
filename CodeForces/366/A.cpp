#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    cout << "I hate";
    for (int i = 1; i < n; i++) {
        cout << " that I " << (i & 1 ? "love" : "hate");
    }
    cout << " it" << endl;
    return 0;
}
