#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int test;cin>>test;
    for(int tst=1;tst<=test;tst++){
        cout<<"Case #"<<tst<<": ";
        int n;cin>>n;
        unordered_set<ll>st,st2;
        while(n--){
            ll p,k;cin>>p>>k;
            if(!p || !k)continue;
            k*=100;
            if(st.empty()){
                for(int i=0;i<10;i++){
                    st.insert(k/(p+(i*1.0)/10));
                }
            }
            else{
                for(int i=0;i<10;i++){
                    if(st.find(k/(p+(i*1.0)/10))!=st.end())
                        st2.insert(k/(p+(i*1.0)/10));
                }
                for(auto it:st2)cout<<it<<endl;
                if(st2.empty()){cout<<-1<<endl;break;}
            }
        }
        if(st2.size()>1)cout<<-1<<endl;
        else cout<<*st2.begin()<<endl;
    }
    return 0;
}

