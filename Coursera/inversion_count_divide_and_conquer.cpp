#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
long long int merge(vector<long long int>&arr,long long int i,long long int k,long long int j)
{
    long long int inv=0;
    vector<long long int>c(j-i+1);
    long long int ptr=0;
    long long int left=i;
    long long int right=k+1;
    while(left<=k && right<=j)
    {
        if(arr[left]<=arr[right])
        {
            c[ptr]=arr[left];
            ptr++;
            left++;
        }
        else
        {
            c[ptr]=arr[right];
            ptr++;
            right++;
            inv=inv+k-left+1;
        }
    }
    while(left<=k)
    {
        c[ptr]=arr[left];
        ptr++;
        left++;
    }
    while(right<=j)
    {
        c[ptr]=arr[right];
        ptr++;
        right++;
    }
    for(long long int p=0;p<ptr;p++)
    {
        arr[i+p]=c[p];
    }
    return inv;

}

long long int mergesort(vector<long long int>&arr,long long int i,long long int j)
{
    if(j-i<=0)
    {
        return 0;
    }
    else
    {
        long long int k=i+((j-i)/2);
        long long int left=mergesort(arr,i,k);
        long long int right=mergesort(arr,k+1,j);
        long long int inv=merge(arr,i,k,j);
        return inv+left+right;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll count1=0;
    int size=100000;
    vector<long long int>arr(size,0);
    for(auto &it:arr)cin>>it;
    count1=mergesort(arr,0,size-1);
    cout<<count1<<endl;
    return 0;
}
