#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string>s;
    string t;
    int mx=0;
    int flag=0;
    while(getline(cin,t)){
        s.push_back(t);
        mx=max(mx,(int)t.length());
    }
    int lim=s.size()+2,i=0,j=0;
    for(i=0;i<lim;i++){
        for(j=0;j<mx+2;j++){
            if(!i || i==lim-1) cout<<"*";
            else{
                if(!j) cout<<"*";
                else if(j<=((mx-s[i-1].length())>>1)+(flag & ((mx-s[i-1].length())&1))) cout<<' ';
                else {
                    if((mx-s[i-1].length()) & 1)flag^=1;
                    cout<<s[i-1];break;
                }
            }
        }
        j+=s[i-1].length();
        while(j<mx+1) {cout<<' ';j++;}
        if(i && i!=lim-1)cout<<"*"<<endl;
        else cout<<endl;
    }
    return 0;
}

