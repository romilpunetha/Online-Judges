#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(string &A)
{
    int len=A.length();
    for(int i=0;i<len-1;i++)
    {
        if(A[i]==A[i+1])
            return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string A;
    cin>>A;
    string ans="";
    while(check(A))
    {
        int len=A.length();
        for(int i=0;i<len;i++)
        {
            int pos=i;
            while(A[i]==A[pos])
            {
                pos++;
            }
            if((pos-i)%2==1)
            {
                ans.push_back(A[i]);
            }
            else if(pos-i==1)
            {
                ans.push_back(A[i]);
            }
            i=pos-1;
        }
        A=ans;
        ans="";
    }
    if(A.length()!=0)
        cout<<A<<endl;
    else
        cout<<"Empty String"<<endl;
    return 0;
}

