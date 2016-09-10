#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int size; cin>>size;
    vector<int>arr(size);
    for(int i=0;i<size;i++) cin>>arr[i];
    int i=0;
    while(i+1<size && arr[i]<=arr[i+1]) i++;
    if(i==size-1){cout<<0<<endl;return 0;}
    i++;
    int pt=i;
    while(i+1<size && arr[i]<=arr[i+1]) i++;
    if(i==size-1 && arr[i]<=arr[0]) cout<<size-pt;
    else cout<<-1;return 0;
}

