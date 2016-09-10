#include <algorithm>
#include <limits.h>
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
#include <string.h>
#include <string>
#include <unordered_map>

using namespace std;

namespace std
{
    template<class RandomIt, class T>
        RandomIt binary_locate(RandomIt first, RandomIt last, const T& val) {
            if(val == *first) return first;
            auto d = std::distance(first, last);
            if(d==1) return first;
            auto center = (first + (d/2));
            if(val < *center) return binary_locate(first, center, val);
            return binary_locate(center, last, val);
        }
}


int main()
{
    ios_base::sync_with_stdio(false);
    long long int size;
    cin>>size;
    vector<long long int>chest(size);
    for(long long int i=0;i<size;i++)
    {
        cin>>chest[i];
    }
    long long int stones,no;
    cin>>stones;
    for(long long int i=0;i<stones;i++)
    {
        cin>>no;
        auto it=binary_locate(chest.begin(),chest.end(),no);
        cout<<distance(chest.begin(),it)+1<<endl;
    }
    return 0;
}
