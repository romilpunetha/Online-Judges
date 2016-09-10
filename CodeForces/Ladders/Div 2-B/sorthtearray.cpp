#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool issorted(vector<int>&arr,int size)
{
    for(int i=0;i<size-1;i++)
    {
        if(arr[i]>arr[i+1])
            return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int size;
    cin>>size;
    vector<int>arr(size);
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    int start=0,end=0;
    for(int i=size-1;i>0;i--)
    {
        if(arr[i]<arr[i-1])
        {
            start=i;
            break;
        }
    }
    end=start-1;
    while(end>=0 && arr[end]>arr[end+1])
    {
        end--;
    }
    end++;
    sort(arr.begin()+end,arr.begin()+start+1);
    //for(auto it:arr)
    //cout<<it<<" ";
    //cout<<endl;
    if(issorted(arr,size))
    {
        cout<<"yes"<<endl;
        cout<<end+1<<" "<<start+1<<endl;
    }
    else
        cout<<"no"<<endl;
    return 0;
}

