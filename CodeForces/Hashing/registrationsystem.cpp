#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    unordered_map<string,int>mp;
    while(n--){
        string s;cin>>s;
        if(mp.find(s)==mp.end()) mp.insert({s,0}),cout<<"OK"<<endl;
        else {
            stringstream ss;
            ss<<++mp[s];
            string res=s+ss.str();
            mp.insert({res,0});
            cout<<res<<endl;}
    }
    return 0;
}

