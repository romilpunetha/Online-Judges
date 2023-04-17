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
#include <utility>
#include <vector>

using namespace std;

int main() {
    string result = "";
    int K, L, m;
    cin >> K >> L >> m;
    char *arr = new char[1000005];
    arr[0] = 's';
    arr[1] = 's';
    arr[K] = 's';
    arr[L] = 's';
    for (int i = 2; i < 1000005; i++) {
        if (i == K || i == L) {
            continue;
        }
        if (arr[i - 1] == 'd' || (i - K >= 1 && arr[i - K] == 'd') || (i - L >= 1 && arr[i - L] == 'd')) {
            arr[i] = 's';
        } else {
            arr[i] = 'd';
        }
    }
    while (m--) {
        int num;
        cin >> num;
        if (arr[num] == 's') {
            result.append("A");
        } else {
            result.append("B");
        }
    }
    cout << result;
    result.clear();
    return 0;
}
