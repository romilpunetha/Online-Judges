#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int len;
    cin>>len;
    vector<int>arr(len);
    for(int i=0;i<len;i++)
    {
        int temp;
        cin>>temp;
        temp--;
        arr[temp]=i+1;
    }
    for(int i=0;i<len;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}

