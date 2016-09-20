#include<bits/stdc++.h>
#define ff first
#define ss second
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
unordered_set<int>st;
set<pair<int,int> >st1,st2;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int test;cin>>test;
    for(int tst=1;tst<=test;tst++){
        int n;cin>>n;
        vector<pair<int,pair<int,int> > >arr(n);
        st.clear();st1.clear();st2.clear();
        for(int i=0;i<n;i++){
            int a,b;cin>>a>>b;
            arr[i]={i,{a,b}};
            st1.insert({a,i});
            st2.insert({b,i});
            st.insert(i);
        }
        bool flag=1,flag2=0;
        while(st.size()>1 && flag){
            pair<int,int>p=*st1.rbegin(),q=*st2.rbegin();
            for(auto &it:arr) if(st.find(it.ff)!=st.end() && it.ss.ff==p.ff && it.ss.ss==q.ff){flag2=1;break;}
            if(flag2)break;
            for(auto &it:arr){
                if(st.find(it.ff)!=st.end() && it.ss.ff!=p.ff && it.ss.ss!=q.ff){
                    flag=1;
                    break;
                }
                else flag=0;
            }
            st1.erase(p);
            st2.erase(q);
            st.erase(p.ss);
            st.erase(q.ss);
        }
        cout<<"Case #"<<tst<<": ";
        if(flag || flag2)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}

