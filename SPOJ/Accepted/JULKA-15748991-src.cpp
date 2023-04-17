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
    vector<int> arr1;
    vector<int> arr2;
    vector<int> result;
    string s;
    for (int test = 0; test < 10; test++) {
        s = "";
        vector<int>(110, 0).swap(arr1);
        vector<int>(110, 0).swap(arr2);
        vector<int>(110, 0).swap(result);
        string a, b;
        cin >> a;
        cin >> b;
        int l1 = a.length();
        int l2 = b.length();
        for (int j = l1 - 1; j >= 0; j--) {
            arr1[l1 - j - 1] = a[j] - '0';
        }
        for (int j = l2 - 1; j >= 0; j--) {
            arr2[l2 - j - 1] = b[j] - '0';
        }
        int carry = 0;
        for (int i = 0; i <= l1; i++) {
            // cout<<"1 = "<<arr1[i]<<" 2 = "<<arr2[i]<<" carry = "<<carry<<endl;
            result[i] = (arr1[i] + arr2[i] + carry) % 10;
            carry = (arr1[i] + arr2[i] + carry) / 10;
            // cout<<"result = "<<result[i]<<" carry = "<<carry<<endl;
        }
        // cout<<"summation = "<<endl;
        // for(int i=0;i<=l1;i++)
        //{
        // cout<< result[i]<<" ";
        // }
        // cout<<endl;
        for (int i = l1; i >= 0; i--) {
            if (result[i] % 2 == 0) {
                result[i] = result[i] / 2;
            } else {
                result[i - 1] = 10 + result[i - 1];
                result[i] = result[i] / 2;
            }
        }
        // cout<<"after division"<<endl;
        // for(int i=0;i<=l1;i++)
        //{
        // cout<< result[i]<<" ";
        // }
        // cout<<endl;
        int i = l1;
        while (result[i--] == 0)
            ;
        i++;
        for (; i >= 0; i--) {
            s.push_back(result[i] + '0');
        }
        cout << s << endl;
        s.clear();
        for (int i = 0; i <= l1; i++) {
            if (result[i] > arr1[i]) {
                result[i] = arr1[i] + 10 - result[i];
                int k = i;
                while (arr1[k + 1] == 0 && k < l1) {
                    arr1[k + 1] = 9;
                    k++;
                }
                arr1[k + 1]--;
            } else {
                result[i] = arr1[i] - result[i];
            }
        }
        i = l1;
        while (result[i--] == 0)
            ;
        i++;
        for (; i >= 0; i--) {
            s.push_back(result[i] + '0');
        }
        if (s.length() == 0) {
            cout << "0" << endl;
        } else {
            cout << s << endl;
        }
    }
    return 0;
}
