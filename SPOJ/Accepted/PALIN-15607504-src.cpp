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

string fill(string str,int i,int j)
{
    while(i>=0)
    {
        str[j++]=str[i--];
    }
    return str;
}

bool ispalindrome(string s)
{
    long long int len=s.length();
    long long int i=0;
    long long int j=len-1;
    if(len==1)
        return true;
    while(i<j)
    {
        if(s[i++]!=s[j--])
            return false;
    }
    return true;
}

bool all9(string s)
{
    int len=s.length();
    int i=0;
    int j=len-1;
    while(i<=j)
    {
        if(s[i++]!='9' || s[j--]!='9')
            return false;
    }
    return true;
}

int main()
{
    string str2;
    string str;
    int test=0;
    cin>>test;
    while(test--)
    {
        cin>>str;
        long long int i=0;
        long long int len=str.length();
        long long int j=len/2;
        if(len%2==0)
        {
            i=len/2-1 ;
        }
        else
        {
            i=len/2;
        }
        if(all9(str))
        {
            str2="1";
            for(int k=0;k<len-1;k++)
            {
                str[k]='0';
            }
            str[len-1]='1';
            str2.append(str);
            str.clear();
            str=str2;
        }
        else
        {
            if(ispalindrome(str))
            {
                if(i==j)
                {
                    if(str[i]=='9')
                    {
                        str[i]='0';
                        while(str[i]=='9')
                        {
                            str[i--]='0';
                            str[j++]='0';
                        }
                        str[i]+=1;
                        str=fill(str,i,j);
                    }
                    else
                    {
                        str[i]+=1;
                    }
                }
                else
                {
                    if(str[i]=='9')
                    {
                        while(str[i]=='9')
                        {
                            str[i--]='0';
                            str[j++]='0';
                        }
                        str[i]+=1;
                        str=fill(str,i,j);
                    }
                    else
                    {
                        str[i]+=1;
                        str=fill(str,i,j);
                    }
                }
            }
            else
            {
                while(str[i]==str[j])
                {
                    i--;
                    j++;
                }
                if(str[i]>str[j])
                {
                    str=fill(str,i,j);
                }
                else
                {
                    if(len%2==0)
                    {
                        i=len/2-1 ;
                    }
                    else
                    {
                        i=len/2;
                    }
                    j=len/2;
                    if(i==j && str[i]=='9')
                    {
                        while(str[i]=='9')
                        {
                            str[i]='0';
                            str[j]='0';
                            i--;
                            j++;
                        }
                        str[i]+=1;
                        str=fill(str,i,j);
                    }
                    else if(i==j)
                    {
                        str[i]+=1;
                        i--;
                        j++;
                        str=fill(str,i,j);
                    }
                    else
                    {
                        str[i]+=1;
                        str=fill(str,i,j);
                    }
                }
            }
        }
        cout<<str<<endl;
        str.clear();
        str2.clear();
    }
    return 0;
}
