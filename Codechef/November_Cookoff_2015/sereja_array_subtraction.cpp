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

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    vector<long long int> arr;
    while (test--) {
        int size = 0;
        cin >> size;
        vector<long long int>(size).swap(arr);
        long long int min = 1000000009;
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
            if (min > arr[i]) {
                min = arr[i];
            }
        }
        // sort(arr.begin(),arr.end());
        long long int sum = 0;
        for (int i = 0; i < size; i++) {
            if (arr[i] % min == 0) {
                arr[i] = min;
            } else {
                arr[i] = arr[i] % min;
                min = arr[i];
                i = -1;
                //    cout<<"min = "<<min<<endl;
            }
        }
        // for(int i=0;i<size;i++)
        //{
        // cout<<arr[i]<<" ";
        //}
        cout << endl;
        for (int i = 0; i < size; i++) {
            sum = sum + arr[i];
        }
        cout << sum << endl;
    }
    return 0;
}
