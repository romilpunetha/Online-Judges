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
#include <string.h>
#include <string>

using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
         long long int num,count=0;
         cin>>num;
        long long int div=5;
        while(num/div !=0)
        {
            count+=num/div;
            div=div*5;
        }
        cout<<count<<endl;
    }
return 0;
}
