#include <limits.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--) {
        int count = 0;
        string s;
        cin >> s;
        int l = s.length();
        string result = "";
        for (int i = 0; i < l - 1; i++) {
            if (s[i] != s[i + 1]) {
                result.push_back(s[i]);
            } else {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}
