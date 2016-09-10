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

int formnum(char a,char b)
{
    int num= ((a-'0')*10)+(b-'0');
    return num;
}

int main()
{
    string s;
    cin>>s;
    vector<unsigned long long int>arr;
    while(1)
    {
        int len=s.length();
        vector<unsigned long long int>(len+10,0).swap(arr);
        arr[0]=1;
        if(s.length()==1 && s[0]=='0')
        {
            break;
        }
        else if(s.length()==1)
        {
            cout<<"1"<<endl;
        }
        else if(s[0]=='0')
        {
            cout<<"0"<<endl;
        }
        else
        {
            arr[1]=1;
            for(int i=1;i<len;i++)
            {
                int num=formnum(s[i-1],s[i]);
                if(num==0)
                {
                    arr[len]=0;
                    break;
                }
                else if(num==10 || num==20)
                {
                    arr[i+1]=arr[i-1];
                }
                else if(num>26 && num%10==0)
                {
                    arr[len]=0;
                    break;
                }
                else if(num>26)
                {
                    arr[i+1]=arr[i];
                }
                else if(num<10)
                {
                    arr[i+1]=arr[i];
                }
                else if(num<=26)
                {
                    arr[i+1]=arr[i]+arr[i-1];
                }
            }
            cout<<arr[len]<<endl;
        }
        s.clear();
        cin>>s;
    }
    return 0;
}
