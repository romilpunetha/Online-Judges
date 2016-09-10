#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1,s2;
    cin>>s1>>s2;
    int i=0;
    int comp=0;
    while(s1[i])
    {
        s1[i]=tolower(s1[i]);
        s2[i]=tolower(s2[i]);
        if(s1[i]<s2[i])
        {
            comp=-1;
            break;
        }
        else if(s1[i]>s2[i])
        {
            comp=1;
            break;
        }
        i++;
    }
    cout<<comp<<endl;
    return 0;
}

