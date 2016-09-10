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

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int a,b;
    cin>>a>>b;
    cout<<a<<" "<<b<<endl;
    int count=0;
    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++)
        {
            int num=rand()%3;
            if(num==0)
            {
                cout<<".";
            }
            else if(num==1)
            {
                cout<<"#";
            }
            else
            {
                if(count<100)
                {
                    cout<<"C";
                    count++;
                }
                else
                {
                    if(rand()%2==0)
                    {
                        cout<<".";
                    }
                    else
                    {
                        cout<<"#";
                    }
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
