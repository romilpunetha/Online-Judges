#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string test="hello";
    int curr=0;
    string s;
    cin>>s;
    int i=0;
    while(s[i] && test[curr])
    {
        if(s[i]==test[curr])
        {
            curr++;
        }
        i++;
    }
    if(!test[curr])
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}

