#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int len=s.size();
    int i=0,pos=-1;
    while(i<len)
    {
        if((s[i]-'0')%2==0)
        {
            pos=i;
            if(s[i]<s[len-1])
            {
                break;
            }
        }
        i++;
    }
    if(pos==-1)
        cout<<-1<<endl;
    else
    {
        char temp=s[len-1];
        s[len-1]=s[pos];
        s[pos]=temp;
        cout<<s<<endl;
    }
    return 0;
}

