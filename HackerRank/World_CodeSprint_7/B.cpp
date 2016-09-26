#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int len,ans=0,cnt=0;cin>>len;
    if(len==1) return cout<<0,0;
    string s;
    cin>>s;
    for(char i='a';i<='z';i++){
        for(char j='a';j<='z';j++){
            cnt=0;
            bool flag=1;
            if(j==i)continue;
            for(int k=0;k<len;k++){
                if(cnt&1){
                    if(s[k]==j)cnt++;
                    else if(s[k]==i){flag=0;break;}
                }
                else{
                    if(s[k]==i)cnt++;
                    else if(s[k]==j){flag=0;break;}
                }
            }
            if(flag)ans=max(ans,cnt);
        }
    }
    cout<<ans<<endl;
    return 0;
}

