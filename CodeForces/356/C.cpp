#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int prime[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 4, 9, 25, 49 };
int main() {
    int cnt = 0;
    string resp;
    for (int i = 0; i < 20; i++) {
        cout << prime[i] << endl;
        cin >> resp;
        if (resp == "yes") cnt++;
    }
    cout << (cnt > 1 ? "composite" : "prime") << endl;
    cout << flush;
    return 0;
}
