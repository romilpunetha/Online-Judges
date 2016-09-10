#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int n,a,ans=0;
bool val(int a){
    return (a>=0 && a<n);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>a;a--;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int i=1;
    ans=arr[a];
    while(val(a+i) || val(a-i)){
        if(val(a+i) && val(a-i) && arr[a+i] && arr[a-i]) ans+=2;
        else if(val(a+i)^val(a-i) && ((val(a-i) && arr[a-i])|| (val(a+i)&& arr[a+i]))) ans++;
        i++;
    }
    cout<<ans<<endl;
    return 0;
}

