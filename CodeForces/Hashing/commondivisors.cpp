#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1,s2;
    cin>>s1>>s2;
    int l1=s1.length(),l2=s2.length();
    if(l1>l2) swap(s1,s2),swap(l1,l2);
    unordered_map<string,int>st;
    for(int i=1;i<=l1/2;i++){
        if(s1[i]==s1[0] && l1%i==0) st.insert({s1.substr(0,i),i});
    }
    int res=0,cnt1=0,cnt2=0,t=0;
    st.insert({s1,l1});
    for(auto &it:st){
        t=0,cnt1=0,cnt2=0;
        while((t=s1.find(it.first,t))!=-1) cnt1++,t+=it.second;
        t=0;
        while((t=s2.find(it.first,t))!=-1) cnt2++,t+=it.second;
        if(cnt1*it.second==l1 && cnt2*it.second==l2)res++;
    }
    cout<<res<<endl;
    return 0;
}

