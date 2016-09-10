#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int test,len;
string s;
int mod=1e9+7;

int distinct(int a,int b,int c){
    set<char>st;
    if(a>=0) st.insert(s[a]);
    st.insert(s[b]);
    if(c<len)st.insert(s[c]);
    return st.size();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>test;
    for(int i=1;i<=test;i++){
        cin>>s;
        len=s.length();
        ll res=1;
        for(int j=0;j<len;j++){
            res=res*distinct(j-1,j,j+1);
            res%=mod;
        }
        cout<<"Case #"<<i<<": "<<res<<endl;
    }
    return 0;
}

