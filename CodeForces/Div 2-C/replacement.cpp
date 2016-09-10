#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int l,m,seg_cnt=0,len=0;cin>>l>>m;
    string s;cin>>s;
    s='x'+s+'x';
    for(int i=0;i<l+2;i++){
        if(s[i]!='.' && s[i+1]=='.') seg_cnt++;
        if(s[i]=='.') len++;
        s[i]=s[i]!='.'?'x':'.';
    }
    while(m--){
        int i;char c;cin>>i>>c;c=c=='.'?'.':'x';
        if((s[i]=='.' && c=='.') || (s[i]!='.' && c!='.')){cout<<len-seg_cnt<<endl;continue;}
        if(c=='.') len++,seg_cnt+=(s[i+1]==s[i-1])?(s[i-1]=='.'?-1:1):0;
        else len--,seg_cnt+=(s[i+1]==s[i-1])?(s[i-1]=='.'?1:-1):0;
        s[i]=c;
        cout<<len-seg_cnt<<endl;
    }
    return 0;
}

