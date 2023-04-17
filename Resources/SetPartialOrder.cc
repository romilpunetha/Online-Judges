
// {{{ VimCoder 0.3.6 <-----------------------------------------------------
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}

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
#include <utility>
#include <vector>

using namespace std;

// }}}

int max(int a, int b) {
    return a > b ? a : b;
}
int min(int a, int b) {
    return a < b ? a : b;
}

class SetPartialOrder {
   public:
    string compareSets(vector<int> a, vector<int> b) {
        int set = 0;
        string result;
        int len1 = a.size();
        int len2 = b.size();
        int l = max(len1, len2);
        int lmin = min(len1, len2);
        int flag = 0;
        if (len1 > len2) {
            flag = 1;
        }
        vector<int> hash(100, -1);
        for (int i = 0; i < l; i++) {
            if (flag == 0) {
                hash[b[i]] = 1;
            } else {
                hash[a[i]] = 1;
            }
        }
        for (int i = 0; i < lmin; i++) {
            if (flag == 0)   // a is greater
            {
                set = 1;
                if (hash[a[i]] != 1) {
                    set = 0;
                    result = "INCOMPARABLE";
                    break;
                }

            } else {
                set = 2;
                if (hash[b[i]] != 1) {
                    set = 0;
                    result = "INCOMPARABLE";
                    break;
                }
            }
        }
        if (set != 0 && len1 == len2) {
            result = "EQUAL";
        } else if (set == 1) {
            result = "LESS";
        } else if (set == 2) {
            result = "GREATER";
        }

        return result;
    }
};
