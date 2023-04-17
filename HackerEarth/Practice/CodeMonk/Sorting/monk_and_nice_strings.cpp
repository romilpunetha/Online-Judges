#include <bits/stdc++.h>
#define tr1(x) cerr << #x << ":\t" << x << endl
#define tr2(x, y) cerr << #x << ":\t" << x << "\t|\t" << #y << ":\t" << y << endl
#define tr3(x, y, z) cerr << #x << ":\t" << x << "\t|\t" << #y << ":\t" << y << "\t|\t" << #z << ":\t" << z << endl
#define tr4(a, b, c, d) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << endl
#define tr5(a, b, c, d, e) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << "\t|\t" << #e << ":\t" << e << endl
#define tr6(a, b, c, d, e, f) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << "\t|\t" << #e << ":\t" << e << "\t|\t" << #f << ":\t" << f << endl
#define base 999983
#define baseinv 943912055
#define ff first
#define ss second
using namespace std;
typedef long long ll;

bool C(const string &s, const string &t) {
    int i = 0, j = 0;
    tr2(s, t);
    while (s[i] && t[j]) {
        tr2(s[i], t[j]);
        if (s[i] < t[j]) return true;
        i++, j++;
    }
    if (i == s.length()) return true;
    return false;
}

int main() {
    int k;
    cin >> k;
    vector<string> arr(k);
    for (int i = 0; i < k; i++) {
        cin >> arr[i];
        int cnt = 0;
        for (int j = 0; j < i; j++) {
            if (C(arr[j], arr[i])) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}
