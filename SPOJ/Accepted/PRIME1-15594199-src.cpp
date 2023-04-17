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
    int test;
    cin >> test;
    vector<int> sieve(100000, 1);
    sieve[0] = 0;
    sieve[1] = 0;
    sieve[2] = 1;
    for (int i = 2; i < 100000; i++) {
        if (sieve[i] == 1) {
            long long int j = i;
            while (i * j < 100000) {
                sieve[i * j] = 0;
                j++;
            }
        }
    }

    // for(int i=0;i<=100;i++)
    //{
    // if(sieve[i]==1)
    //{
    // cout<<i<<endl;
    // }
    // }

    while (test--) {
        long long int m, n;
        cin >> m >> n;
        // vector<int>sieve2(n-m,1);
        int *sieve2 = new int[n - m + 1];
        for (int i = 0; i <= n - m; i++) {
            sieve2[i] = 1;
        }
        for (long long int i = 0; i * i <= n; i++) {
            if (sieve[i] == 1) {
                long long int j = m / i;
                if (j * i < m) {
                    j++;
                }
                while (i * j <= n) {
                    sieve2[(j * i) - m] = 0;
                    j++;
                }
            }
        }
        long long int t = m;
        while (m <= n && m < 100000) {
            if (sieve[m] == 1) {
                cout << m << endl;
            }
            m++;
        }
        while (m <= n) {
            if (sieve2[m - t] == 1) {
                cout << m << endl;
            }
            m++;
        }
        cout << endl;
        delete[] sieve2;
    }
    return 0;
}
