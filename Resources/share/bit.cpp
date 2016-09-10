#include<iostream>
#include<stdio.h>
#include<string.h>
#define ll long long
using namespace std;
void update(ll int *tree,ll int n,ll int index,ll int val)
{
	while(index<=n)
	{
		tree[index]+=val;
		index+=(index & (-index));
	}
}
ll int query(ll int *tree,ll int n,ll int index)
{
	ll int sum=0;
	while(index>0)
	{
		sum+=tree[index];
		index-=(index &(-index));
	}
	return sum;
}
void construct(ll int *tree,ll int *arr,ll int n)
{
	 ll int i;
	 for(i=1;i<=n;i++)
	 update(tree,n,i,arr[i]);
}
int main()
{
	ll int n=13;
	ll int arr[13]={0,2,1,1,3,2,3,4,5,6,7,8,9};
	ll int tree[n+1];
	memset(tree,0,sizeof(tree));
	construct(tree,arr,n-1);
	cout<<query(tree,1,6)<<endl;
	update(tree,n,4,6);
	cout<<query(tree,1,6)<<endl;
}
