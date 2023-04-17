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

double result(int hx, int hy, int sx, int sy) {
    return sqrt(pow(hx - sx, 2) + pow(hy - sy, 2));
}

int main() {
    ios_base::sync_with_stdio(false);
    int hx, hy, sx, sy;
    cin >> hx >> hy >> sx >> sy;
    cout << fixed;
    cout << setprecision(5) << result(hx, hy, sx, sy) << endl;
    return 0;
}
