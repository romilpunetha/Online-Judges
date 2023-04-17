#include <bits/stdc++.h>
#define endl '\n'
#define inf INT_MAX
#define pb push_back
#define present(c, x) ((c).find(x) != (c).end())
#define base 999983
#define baseinv 943912055
#define ff first
#define ss second
#define tr1(x) cerr << #x << ": " << x << endl;
#define tr2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define tr3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define tr4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define tr5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define tr6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

void parse2(string &s, string &t) {
    // tr2(s, t);
    if (s == "toupper")
        for (auto &it : t) it = toupper(it);
    else if (s == "tolower")
        for (auto &it : t) it = tolower(it);
    else {
        auto it = s.find("_");
        string temp = s.substr(it + 1);
        t += temp;
    }
}

void parse(string s, char delim) {   // careful about call by value
    s += delim;
    int prev = 0, curr = 0;
    vector<string> arr;
    while ((curr = s.find(delim, prev)) != string::npos) {
        string subst = s.substr(prev, curr - prev);
        arr.push_back(subst);
        prev = curr + 1;
    }
    int n = arr.size();
    for (int i = n - 2; i >= 0; i--) parse2(arr[i], arr[n - 1]);
    cout << arr[n - 1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    string s;
    while (getline(cin, s)) parse(s, ' ');
    return 0;
}
