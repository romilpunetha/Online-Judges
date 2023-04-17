
// {{{
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
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define FOR(i, x, y) for (long long int i = (x); i <= (y); ++i)
#define ROF(i, x, y) for (long long int i = (y); i >= (x); --i)
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define all(x) (x).begin(), (x).end()
#define lcm(x, y) (((x) / gcd((x), (y))) * (y))
#define abs(x) ((x) < 0 ? -(x) : (x))
#define sq(x) ((x) * (x))
// }}}
using namespace std;
// }}}

int main() {
    ios_base::sync_with_stdio(false);
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b + c == 42) {
        cout << a << "+" << b << "+" << c << endl;
    } else if (a + b * c == 42) {
        cout << a << "+" << b << "*" << c << endl;
    } else if (a * b * c == 42) {
        cout << a << "*" << b << "*" << c << endl;
    } else if (a * b + c == 42) {
        cout << a << "*" << b << "+" << c << endl;
    } else {
        cout << "This is not the ultimate question" << endl;
    }
    return 0;
}
