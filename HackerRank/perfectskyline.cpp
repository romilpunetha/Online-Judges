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
    int size;
    cin >> size;
    vector<int> A(size);
    for (int i = 0; i < size; i++) {
        cin >> A[i];
    }
    if (size % 2 == 0) {
        cout << "Not Perfect" << endl;
    } else {
        int a = 0, b = size - 1;
        while (a < b) {
            if (a > 0 && b < size - 1) {
                if (A[a - 1] >= A[a] || A[b + 1] >= A[b]) {
                    cout << "Not Perfect" << endl;
                    break;
                }
            }
            if (A[a] != A[b]) {
                cout << "Not Perfect" << endl;
                break;
            } else {
                a++;
                b--;
            }
        }
        if (a == b) {
            cout << "Perfect" << endl;
        }
    }
    return 0;
}
