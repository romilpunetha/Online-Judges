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
#define even 1
#define odd 2
using namespace std;

bool stop = false;

void deleteradius(vector<vector<pair<bool, bool> > >& dp, map<int, list<int> > rtog, map<int, list<int> > indextor, list<int> l, int size) {
    list<int>::iterator i;
    map<int, list<int> >::iterator k;
    for (i = l.begin(); i != l.end(); i++) {
        for (k = indextor.begin(); k != indextor.end(); k++) {
            (*k).remove(*i);
        }
    }
}
void getresult(vector<vector<pair<bool, bool> > >& dp, map<int, list<int> > rtog, map<int, list<int> > indextor, int status, int row, int col) {
    dp[row][col].first = true;
    map<int, list<int> >::iterator i;
    map<int, list<int> >::iterator k;
    for (i = rtog.begin(); i != rtog.end(); i++) {
        deleteradius(dp, rtog, indextor, (*i), row - 1);
        if (stop == true) {
            cout << "Sage" << endl;
            return;
        }
    }
    for (k = indextor.begin(); k != indextor.end(); k++) {
        deletegradient(dp, rtog, indextor, *k);
        if (stop == true) {
            cout << "Sage" << endl;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--) {
        stop = false;
        int crackers;
        cin >> crackers;
        map<int, list<int> > rtog;
        map<pair<int, int>, int> gtoindex;
        map<int, list<int> > indextor;
        for (int i = 0; i < crackers; i++) {
            int r, a, b;
            cin >> r >> a >> b;
            if (gtoindex.find(make_pair(a, b)) != gtoindex.end()) {
                gtoindex[make_pair(a, b)] = i + 1;
            }
            rtog[r].push_back(gtoindex[make_pair(a, b)]);
            indextor[gtoindex[make_pair(a, b)]].push_back(r);
        }
        int rsize = rtog.size();
        int gsize = gtoindex.size();
        vector<vector<pair<bool, bool> > > dp(rsize + 1, vector<pair<bool, bool> >(gsize + 1, make_pair(false, false)));
        getresult(dp, rtog, indextor, odd, rsize, gsize);
    }
    return 0;
}
