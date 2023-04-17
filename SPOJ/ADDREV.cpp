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

long long int rev(long long int a) {
    long long int res = 0;
    while (a) {
        res = res * 10 + a % 10;
        a = a / 10;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--) {
        int a, b;
        cin >> a >> b;
        a = rev(a);
        b = rev(b);
        a = a + b;
        cout << rev(a) << endl;
    }
    return 0;
}
