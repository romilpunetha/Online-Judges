#include<bits/stdc++.h>
using namespace std;
#define prime_no 101
int createHash(string str)
{
    int n=str.length();
    int hash=0;
    for(int i=0;i<n;i++)
        hash+=pow(prime_no,i)*(str[i]-'a'+1);
    return hash;
}
int recalculateHash(string str,int oldHash)
{
    int m=str.length();
    int x=oldHash-(str[0]-'a'+1);
    x=x/prime_no;
    int newHash=x+pow(prime_no,m-2)*(str[m-1]-'a'+1);
    return newHash;
}
int rabinKarp(string text,string pat)
{
    int i,m=pat.length();
    int n=text.length();
    int patternHash=createHash(pat);
    int textHash=createHash(text.substr(0,m));
    for(i=1;i<=n-m;i++)
    {
        if(textHash==patternHash && pat.compare(text.substr(i-1,m))==0)
            return i-1;
        textHash=recalculateHash(text.substr(i-1,m+1),textHash);
    }
    if(textHash==patternHash && pat.compare(text.substr(i-1,m))==0)
        return i-1;
    return -1;

}
int main()
{
    string s,p;
    cin>>s>>p;
    cout<<rabinKarp(s,p)<<endl;
    return 0;
}
