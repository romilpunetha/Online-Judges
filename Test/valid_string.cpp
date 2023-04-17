#include <bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define dead 99;
using namespace std;
typedef long long ll;

bool num(char i) {
    return (i >= '0' && i <= '9');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int len = s.length();
    int i = 0, state = 0, pos = 1, flag = 0;
    stack<int> st;
    while (i < len) {
        switch (state) {
            case 0: {
                if (s[i] == '[') {
                    st.push(pos++);
                    state = 1;
                } else
                    state = dead;
                i++;
                break;
            }
            case 1: {
                if (s[i] == '[') {
                    st.push(pos++);
                    i++;
                    continue;
                } else if (s[i] == ' ')
                    state = 2;
                else if (num(s[i]))
                    state = 5;
                else if (s[i] == ']')
                    state = 3;
                else
                    state = dead;
                i++;
                break;
            }
            case 2: {
                if (s[i] == ' ') {
                    i++;
                    continue;
                } else if (num(s[i]))
                    state = 5;
                else if (s[i] == ']')
                    state = 3;
                else
                    state = dead;
                i++;
                break;
            }
            case 3: {
                if (!st.empty())
                    st.pop();
                else if (st.empty()) {
                    state = dead;
                } else if (s[i] == ' ' || s[i] == ']') {
                    i++;
                    continue;
                } else if (s[i] == ',')
                    state = 4;
                else
                    state = dead;
                i++;
                break;
            }
            case 4: {
                if (s[i] == ' ') {
                    i++;
                    continue;
                } else if (s[i] == '[')
                    state = 1;
                else
                    state = dead;
                i++;
                break;
            }
            case 5: {
                if (num(s[i])) {
                    i++;
                    continue;
                } else if (s[i] == ' ')
                    state = 6;
                else
                    state = dead;
                i++;
                break;
            }
            case 6: {
                if (s[i] == ' ') {
                    i++;
                    continue;
                } else if (s[i] == ',')
                    state = 7;
                else if (s[i] == ']')
                    state = 8;
                else
                    state = dead;
                i++;
                break;
            }
            case 7: {
                if (s[i] == ' ') {
                    i++;
                    continue;
                } else if (num(s[i]))
                    state = 5;
                else
                    state = dead;
                i++;
                break;
            }
            case 8: {
                if (!st.empty())
                    st.pop();
                else if (st.empty()) {
                    state = dead;
                } else if (s[i] == ']') {
                    i++;
                    continue;
                } else if (s[i] == ' ')
                    state = 9;
                else
                    state = dead;
                i++;
                break;
            }
            case 9: {
                if (s[i] == ' ') {
                    i++;
                    continue;
                } else if (s[i] == ',')
                    state = 7;
                else
                    state = dead;
                i++;
                break;
            }
            default: {
                flag = 1;
                i = INT_MAX;
            }
        }
    }
    if (!st.empty()) flag = 1;
    cout << (!flag ? "Valid" : "Invalid") << endl;
    return 0;
}
