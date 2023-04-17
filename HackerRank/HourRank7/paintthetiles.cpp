#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N;
    string s;
    cin >> N;
    cin >> s;
    int l = s.length();
    int i = 0, count = 0;
    while (i < l) {
        while (i < l && s[i] == s[i + 1]) {
            i++;
        }
        count++;
        i++;
    }
    cout << count << endl;
    return 0;
}
