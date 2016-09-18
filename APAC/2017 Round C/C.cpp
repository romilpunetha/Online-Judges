#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int t;
unordered_map<string,ll>mp;

vector<ll> indeg;
list<ll> *g;

void parse(string &s){
    int a=s.find('=');
    s.pop_back();
    s+=',';
    string var=s.substr(0,a);
    if(mp.find(var)==mp.end()) mp[var]=t++;
    a=s.find('(');a++;
    int prev=a;
    while((a=s.find(',',prev+1))!=string::npos){
        string var2=s.substr(prev,a-prev);
        if(var2.length()){
            if(mp.find(var2)==mp.end()) mp[var2]=t++;
            indeg[mp[var]]++;
            g[mp[var2]].push_back(mp[var]);
            prev=a+1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int test;cin>>test;
    for(int tst=1;tst<=test;tst++){
        int n;cin>>n;
        t=1;
        mp.clear();
        g=new list<ll>[110000];
        indeg.clear();indeg.resize(110000,0);
        for(int i=0;i<n;i++){
            string s;cin>>s;
            parse(s);
        }
        unordered_set<ll>st;
        for(auto &it:mp){
            if(!indeg[it.second])st.insert(it.second);
        }
        int flag=0;
        while(!st.empty()){
            int u=*st.begin();
            st.erase(*st.begin());
            for(auto &it:g[u]){
                indeg[it]--;
                if(!indeg[it])st.insert(it);
            }
        }
        if(mp.size()!=n)flag=1;
        for(auto &it:mp){
            if(indeg[it.second]){flag=1;break;}
        }
        cout<<"Case #"<<tst<<": ";
        if(flag)cout<<"BAD\n";
        else cout<<"GOOD\n";
    }
    return 0;
}

