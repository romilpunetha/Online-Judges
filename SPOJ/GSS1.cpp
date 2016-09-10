#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int n,m;
int *arr;
ll *pre,*suf;

int main(){
    scanf(" %d",&n);
    arr=new int[n];
    pre=new ll[n];
    suf=new ll[n];
    memset(arr,0,sizeof(arr));
    memset(arr,0,sizeof(pre));
    memset(arr,0,sizeof(suf));
    for(int i=0;i<n;i++) scanf(" %d",&arr[i]);
    for(int i=0;i<n;i++){
        if(i) pre[i]+=pre[i-1]+arr[i];
        else pre[i]=arr[i];
        int k=n-i-1;
        if(k<n-1) suf[k]+=suf[k+1]+arr[k];
        else suf[k]=arr[k];
    }

    return 0;
}

