#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int test;cin>>test;
    for(int tst=1;tst<=test;tst++){
        cout<<"Case #"<<tst<<": ";
        ll n,p,q,res;cin>>n;
        unordered_set<ll>st1,st2;
        for(int i=0;i<n;i++){
            cin>>p>>q;
            if(!q){i--,n--;continue;}
            for(int j=0;j<100;j++){
                res= ((q*100.0)/((long double)p+j/100.0));
                if(!i) st1.insert(res);
                else if(st1.find(res)!=st1.end()){st2.insert(res);}
            }
            if(i)for(auto &it:st1)cout<<it<<" ";cout<<endl;
            if(i)swap(st1,st2),st2.clear();
        }
        if(p==100) cout<<q<<endl;
        else{
            if(st1.size()!=1)cout<<-1<<endl;
            else cout<<*st1.begin()<<endl;
        }
    }
    return 0;
}

