#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    string s;cin>>s;
    int len=s.length();
    unordered_set<char>st;
    if(s.length()<26)return cout<<-1,0;
    for(char i='A';i<='Z';i++)st.insert(i);
    int i=0,cnt=0,start=0;
    while(s[i]){
        while(s[i] && st.size()-cnt>0){
            cnt+=s[i]=='?';
            if(s[i]=='?'){i++;continue;}
            if(st.find(s[i])!=st.end()) st.erase(s[i++]);
            else break;
        }
        if(st.size()-cnt==0)break;
        while(start<i && st.find(s[i])==st.end()){
            cnt-=s[start]=='?';
            if(s[start]!='?')st.insert(s[start]);
            start++;
        }
    }
    if(st.size()-cnt==0){
        for(int j=0;j<len;j++){
            if(s[j]=='?'){
                if(j>=start && j<i) s[j]=*st.begin(),st.erase(st.begin());
                else s[j]='A';
            }
        }
        cout<<s;
    }
    else cout<<-1;
    return 0;
}
