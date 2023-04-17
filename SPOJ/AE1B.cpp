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
    int size, screws, tables;
    int count = 0;
    cin >> size >> screws >> tables;
    long long int total = screws * tables, sum = 0;
    vector<int> arr(size, 0);
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int i = size - 1;
    while (total > sum) {
        sum += arr[i--];
        count++;
    }
    cout << count << endl;
    return 0;
}
