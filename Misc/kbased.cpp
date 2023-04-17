/*
Let’s consider K-based numbers, containing exactly N digits. We define a number to be valid if its K-based notation doesn’t contain two successive zeros. For example:

    1010230 is a valid 7-digit number;
    1000198 is not a valid number;
    0001235 is not a 7-digit number, it is a 4-digit number.

Given two numbers N and K, you are to calculate an amount of valid K based numbers, containing N digits.
You may assume that 2 ≤ K ≤ 10; N ≥ 2; N + K ≤ 18.
Input
The numbers N and K in decimal notation separated by the line break.
Output
The result in decimal notation.
Sample
input	output

2		90
10
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <utility>   // std::pair, std::make_pair
#include <vector>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int> > arr(n + 1, make_pair(0, 0));
    arr[0] = make_pair(0, 0);
    arr[1] = make_pair(0, k - 1);
    vector<pair<int, int> >::iterator itr = arr.begin();
    if (n == 1) {
        cout << k - 1 << endl;
        return 0;
    }
    int endingwith0 = 0;
    int notendingwith0;
    int i = 2;
    itr++;
    int ans;
    for (; itr != arr.end(); itr++) {
        int fst = itr->first;
        int sec = itr->second;
        endingwith0 = sec;
        notendingwith0 = fst * 9 + sec * 9;
        arr[i] = make_pair(endingwith0, notendingwith0);
        // cout<<itr->first<<" "<<itr->second<<endl;
        ans = fst + sec;
        i++;
    }
    cout << ans << endl;
    return 0;
}