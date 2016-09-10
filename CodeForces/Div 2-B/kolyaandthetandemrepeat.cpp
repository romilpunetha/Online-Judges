#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
string s;
int l,k,i,j,ki,mx=0,cnt=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s>>ki;
    l=s.length();
    for(i=1;i<=(l+ki)>>1;i++){
        for(j=0;j<l+ki;j++){
            if(j+2*i-1>=l+ki) break;
            cnt=0;
            for(k=j;k<j+i;k++){
                if((k+i>=l) || (s[k]==s[k+i])) cnt++;
                else break;
            }
            mx=max(mx,cnt);
        }
    }
    cout<<2*mx<<endl;
    return 0;
}

