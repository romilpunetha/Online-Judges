#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;
int n;
vector<string> arr(110);

string isPangram() {
    string res;
    for (int i = 0; i < n; i++) {
        int j = 0;
        unordered_set<char> st;
        while (arr[i][j]) {
            if (arr[i][j] >= 'a' && arr[i][j] <= 'z') st.insert(arr[i][j]);
            j++;
        }
        if (st.size() == 26)
            res = res + '1';
        else
            res = res + '0';
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    cin.ignore(INT_MAX, '\n');
    for (int i = 0; i < n; i++) {
        getline(cin, arr[i]);
    }
    cout << isPangram() << endl;
    return 0;
}
