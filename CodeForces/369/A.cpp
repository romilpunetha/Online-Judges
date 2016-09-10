#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n,flag=0;cin>>n;
    vector<string>s(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
        if(!flag && s[i][0]=='O' && s[i][1]=='O') flag=1,s[i][0]='+',s[i][1]='+';
        if(!flag && s[i][3]=='O' && s[i][4]=='O') flag=1,s[i][3]='+',s[i][4]='+';
    }
    if(flag){
        cout<<"YES\n";
        for(auto &it:s)cout<<it<<endl;
    }
    else cout<<"NO"<<endl;
    return 0;
}

