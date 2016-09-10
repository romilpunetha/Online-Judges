#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int n,p,ans=0,start=-1,ed=0;
string s;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>p>>s;
    if(p>n/2)p=n-p+1;
    p--;
    for(int i=0;i<n/2;i++){
        ans+=min(abs(s[i]-s[n-i-1]),26-abs(s[i]-s[n-i-1]));
        if(start==-1 && s[i]!=s[n-i-1])start=i;
        if(s[i]!=s[n-i-1])ed=i;
    }
    if(start!=-1){
        ans+=(p>=start && p<=ed)?ed-start+min(ed-p,p-start):0;
        ans+=p<start?ed-p:0;
        ans+=p>ed?p-start:0;
    }
    cout<<ans<<endl;
    return 0;
}
