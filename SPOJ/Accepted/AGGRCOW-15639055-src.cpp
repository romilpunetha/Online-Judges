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
int turn=1;
bool ispossible(vector<long long int>&barn,vector<long long int>&is_at,int cows,long long int mid)
{
    is_at.clear();
    //cout<<"turn = "<<turn++<<endl;
    //cout<<"mid = "<<mid<<endl;
    int len=barn.size();
    int loc=0;
    int i=0;
    is_at.push_back(barn[0]);
    for(i=1;i<len;i++)
    {
        //cout<<"barn["<<i<<"] = "<<barn[i]<<" and is_at["<<loc<<"] = "<<is_at[loc]<<endl;
        if(barn[i]-is_at[loc]>=mid)
        {
            //cout<<"if condition true"<<endl;
            //cout<<"barn["<<i<<"] = "<<barn[i]<<" and is_at["<<loc<<"] = "<<is_at[loc]<<endl;
            is_at.push_back(barn[i]);
            loc++;
        }
        if((int)is_at.size()==cows)
        {
            break;
        }
    }
    for(int i=0;i<=loc;i++)
    {
        //cout<<"is_at = "<<is_at[i]<<endl;
    }
    //cout<<endl;
    if((int)is_at.size()==cows)
    {
        //cout<<"returning true"<<endl;
        return true;
    }
    else
    {
        //cout<<"returning false"<<endl;
        return false;
    }
}

int main()
{
    int test;
    cin>>test;
    vector<long long int>barn;
    vector<long long int>is_at;
    while(test--)
    {
        turn=1;
        int stalls=0;
        int cows=0;
        cin>>stalls>>cows;
        vector<long long int>(stalls,0).swap(barn);
        for(int i=0;i<stalls;i++)
        {
            cin>>barn[i];
        }
        sort(barn.begin(),barn.end());
        //cout<<"barn = "<<endl;
        //for(int i=0;i<stalls;i++)
        //{
        //cout<<barn[i]<<" ";
        //}
        //cout<<endl;
        long long int start=1,end=barn[stalls-1]-barn[0];
        long long int min=INT_MAX;
        while(start<end)
        {
            long long int mid=(start+end)/2;
            if(ispossible(barn,is_at,cows,mid))
            {
                start=mid+1;
                min=mid;
            }
            else
            {
                end=mid;
            }
        }
        cout<<min<<endl;
    }
    return 0;
}
