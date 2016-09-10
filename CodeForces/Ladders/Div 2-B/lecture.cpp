#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int len1,len2;
    cin>>len1>>len2;
    unordered_map<string,string>m;
    for(int i=0;i<len2;i++)
    {
        string s,t;
        cin>>s>>t;
        m[s]=t;
    }
    for(int i=0;i<len1-1;i++)
    {
        string s;
        cin>>s;
        if(s.length()<=m[s].length())
            cout<<s<<" ";
        else
            cout<<m[s]<<" ";
    }
    string s;
    cin>>s;
    if(s.length()<=m[s].length())
        cout<<s<<endl;
    else
        cout<<m[s]<<endl;
    return 0;
}

