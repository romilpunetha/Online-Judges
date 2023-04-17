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

int max(int a, int b) {
    return (a > b ? a : b);
}

void display(vector<vector<int> >& arr, int j) {
    for (int p = 0; p < 2; p++) {
        for (int q = 1; q <= j; q++) {
            cout << arr[p][q] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int budget, party;
    cin >> budget >> party;
    while (!(budget == 0 && party == 0)) {
        vector<vector<int> > arr(2, vector<int>(budget + 1, 0));
        int fee, fun;
        for (int i = 0; i < party; i++) {
            cin >> fee >> fun;
            for (int j = 1; j <= budget; j++) {
                if (arr[(i + 1) % 2][j] != 0) {
                    if (j + fee <= budget) {
                        arr[(i) % 2][j + fee] = max(arr[i % 2][j + fee], fun + arr[(i + 1) % 2][j]);
                    }
                }
            }
            arr[i % 2][fee] = max(fun, arr[i % 2][fee]);
            for (int j = 1; j <= budget; j++) {
                arr[(i) % 2][j] = max(arr[(i + 1) % 2][j], arr[i % 2][j]);
            }
            for (int j = 1; j <= budget; j++) {
                arr[(i + 1) % 2][j] = 0;
            }
            // display(arr,budget);
            // cout<<endl;
        }
        int a = 0, b = 0;
        for (int i = budget; i >= 1; i--) {
            if (arr[0][i] >= a) {
                a = arr[0][i];
                b = i;
            }
            if (arr[1][i] >= a) {
                a = arr[1][i];
                b = i;
            }
        }
        cout << b << " " << a << endl;
        cin >> budget >> party;
    }

    return 0;
}
