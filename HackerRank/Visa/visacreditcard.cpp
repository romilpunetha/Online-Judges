#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;

list<int>*g;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int test;cin>>test;
    for(int tst=1;tst<=test;tst++){
        int n,i,j=0;cin>>n;
        g=new list<int>[10];
        vector<int>in(10,0);
        vector<string>arr(n);
        string s;
        while(n--){
            i=1;
            cin>>s;
            arr[j++]=s;
            while(s[i]){
                if(s[i-1]!=s[i]){
                    g[s[i-1]-'0'].push_back(s[i]-'0');
                    in[s[i]-'0']++;
                }
                i++;
            }
        }
        bool flag=0;
        unordered_set<int>st;
        unordered_map<int,int>mp;
        i=0;
        for(int i=0;i<10;i++)if(!in[i])st.insert(i);
        while(!st.empty()){
            if(st.size()>1){flag=1;break;}
            int u=*st.begin();
            st.erase(u);
            mp[u]=i++;
            for(auto &it:g[u]){
                in[it]--;
                if(!in[it])st.insert(it);
            }
        }
        for(auto &it:in)flag=flag | it;
        if(flag)cout<<-1<<endl;
        else{
            for(auto &it:arr){
                for(auto &jt:it){
                    jt='0'+ mp[jt-'0'];
                }
                cout<<it<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}

