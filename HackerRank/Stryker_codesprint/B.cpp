#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n,b;cin>>n>>b;
    unordered_map<int,pair<double,pair<double,double> > >mp;
    set<pair<pair<double,int>,pair<double,double> > >st;
    for(int i=0;i<n;i++){
        int id;
        double x,y,z;cin>>id>>x>>y>>z;
        st.insert({{z,id},{x,y}});
    }
    for(int i=0;i<b;i++){
        auto it=*st.rbegin();
        st.erase(*st.rbegin());
        mp[it.ff.ss]={it.ss.ff,{it.ss.ss,it.ff.ff}};
    }
    char c;int id;
    while(cin>>c){
        cin>>id;
        if(c=='F' || c=='f'){
            if(mp.find(id)!=mp.end()) cout<<fixed<<setprecision(3)<<id<<" = ("<<mp[id].ff<<","<<mp[id].ss.ff<<","<<mp[id].ss.ss<<")\n";
            else cout<<"Point doesn't exist in the bucket.\n";
        }
        else {
            if(mp.find(id)==mp.end()) cout<<"Point doesn't exist in the bucket.\n";
            else {
                if(st.size()==0) cout<<"No more points can be deleted.\n";
                else {
                    mp.erase(id);
                    cout<<"Point id "<<id<<" removed.\n";
                    auto it=*st.rbegin();
                    st.erase(*st.rbegin());
                    mp[it.ff.ss]={it.ss.ff,{it.ss.ss,it.ff.ff}};
                }
            }
        }
    }
    return 0;
}

