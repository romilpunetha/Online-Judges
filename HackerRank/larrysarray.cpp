#include<iostream>
#include<vector>
using namespace std;

int merge(vector<int>&arr,vector<int>&temp,int left,int mid,int right)
{
    int i,j,k;
    int inv=0;
    i=left;
    j=mid;
    k=left;
    while(i<=mid-1 && j<=right)
    {
        if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
        else
        {
            temp[k++]=arr[j++];
            inv+=mid-i;
        }
    }
    while(i<=mid-1)
        temp[k++]=arr[i++];
    while(j<=right)
        temp[k++]=arr[j++];
    for(int i=left;i<=right;i++)
    {
        arr[i]=temp[i];
    }
    return inv;
}

int mergesort(vector<int>&arr,vector<int>&temp,int left,int right)
{
    int mid,inv=0;
    if(right>left)
    {
        mid=(right+left)/2;
        inv+=mergesort(arr,temp,left,mid);
        inv+=mergesort(arr,temp,mid+1,right);
        inv+=merge(arr,temp,left,mid+1,right);
    }
    return inv;
}

int findInversion(vector<int> &arr,int size)
{
    vector<int> temp(size,0);
    return mergesort(arr,temp,0,size-1);
}

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int size;
        cin>>size;
        vector<int>arr(size,0);
        for(int i=0;i<size;i++)
        {
            cin>>arr[i];
        }
        int inversion = findInversion(arr,size);
        if(inversion%2==0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
