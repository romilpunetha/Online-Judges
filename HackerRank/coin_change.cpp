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
    int val, size;
    cin >> val >> size;
    vector<int> arr(size, 0);
    vector<vector<int> > dp(size, vector<int>(val + 1, 0));
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int temp = arr[0];
    // cout<<"temp = "<<temp<<endl;
    while (temp <= val) {
        dp[0][temp] = 1;
        temp = temp + arr[0];
    }
    // cout<<"temp = "<<temp<<endl;
    // for(int i=0;i<=val;i++)
    //{
    // cout<<dp[0][i]<<" ";
    // }
    // cout<<endl;
    for (int i = 1; i < size; i++) {
        int k = 1;
        while (arr[i] * k <= val) {
            dp[i][arr[i] * k]++;
            k++;
        }

        for (int j = 1; j <= val; j++) {
            if (dp[i - 1][j] > 0 && arr[i] + j <= val) {
                dp[i][arr[i] + j]++;
            }
        }
        for (int j = 1; j <= val; j++) {
            dp[i][j] += dp[i - 1][j];
        }
    }
    for (int i = 0; i <= val; i++) {
        cout << dp[size - 1][i] << " ";
    }
    cout << endl;
    cout << dp[size - 1][val] << endl;
    return 0;
}
