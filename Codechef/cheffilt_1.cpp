#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <iostream>
#define gc getchar_unlocked
#define FOR(i,x,y) for(int i = (x) ; i <= (y) ; ++i)
using namespace std;
typedef long long int ll;
inline void scanint(int &x)
{
    int c=gc();
    for(;c<48 || c>57;c=gc());
    x=0;
    for(;c>47 && c<58;c=gc())
    {
        x=(x<<1)+(x<<3)+c-48;
    }
}
inline void write(int x)
{
    char buffor[35];
    int i=0;
    do
    {
        buffor[i++]=(x%10)+'0';
        x/=10;
    } while(x);
    i--;
    while(i>=0) putchar_unlocked(buffor[i--]);
    putchar_unlocked('\n');
}

int dp[2][1025];

int main()
{
    int test;
    scanint(test);
    int mod=1000000007;
    while(test--)
    {
        FOR(i,0,1023)
        {
            dp[0][i]=0;
        }
        dp[0][0]=1;
        int pic=0,filt=1023;
        char c[11];
        gets(c);
        FOR(i,0,9)
        {
            pic<<=1;
            c[i]=='b'?pic|=1:true;
        }
        int n=0;
        scanint(n);
        int res=pic^filt;
        int g;
        int h;
        FOR(i,1,n)
        {
            g=i%2;
            h=(i+1)%2;
            pic=0;
            gets(c);
            FOR(j,0,9)
            {
                pic<<=1;
                c[j]=='+'?pic|=1:true;
            }
            FOR(j,0,1023)
            {
                dp[g][j]=(dp[h][j]+dp[h][j^pic])%mod;
            }
        }
        write(dp[g][res]);
    }
    return 0;
}
