
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
        int s, n;
        cin >> s >> n;
        vector<int> arr(s);
        for (int i = 0; i < s; i++) {
            cin >> arr[i];
        }
        int min = INT_MAX;
        sort(arr.begin(), arr.end());
        for (int i = 0; i + n - 1 < s; i++) {
            if (arr[i + n - 1] - arr[i] < min) {
                min = arr[i + n - 1] - arr[i];
            }
        }
        cout << min << endl;
    }

    return 0;
}
