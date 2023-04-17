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
#include <utility>
#include <vector>
// #include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--) {
        int size;
        cin >> size;
        vector<int> arr(size, 0);
        for (int i = 0; i < size; i++) {
            int temp;
            cin >> temp;
            if (arr[i] == 0) {
                arr.push_back(temp);
            } else {
            }
        }
    }
    return 0;
}
