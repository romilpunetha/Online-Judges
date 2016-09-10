#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int test;cin>>test;
    for(int t=1;t<=test;t++){
        ll n,l1,r1,A,B,c1,c2,m,sum=0,active=0,start=0,sst=0;
        cin>>n>>l1>>r1>>A>>B>>c1>>c2>>m;
        vector<pair<ll,ll> >x(2*n);
        vector<ll>ans(n+1,0);
        unordered_set<ll>st;
        c1%=m,c2%=m;
        x[0]={l1,-1};
        x[1]={r1,1};
        for(int i=1;i<n;i++){
            ll t1=(A*l1 + B*r1 + c1)%m;
            ll t2=(A*r1 + B*l1 + c2)%m;
            x[2*i]={min(t1,t2),-(i+1)};
            x[2*i+1]={max(t1,t2),i+1};
            l1=t1,r1=t2;
        }
        sort(x.begin(),x.end());
        for(int i=0;i<2*n;i++){
            if(x[i].second<0){
                active++;
                if(active==1)start=i,sst=i;
                else if(active==2) ans[*st.begin()]+=x[i].first-x[start].first-!(abs(x[start].second)==abs(*st.begin()));
                st.insert(-x[i].second);
            }
            else {
                active--;
                if(!active){
                    sum+=x[i].first-x[sst].first+1;
                    ans[*st.begin()]+=x[i].first-x[start].first;
                    if(abs(x[i].second)==abs(x[start].second))ans[*st.begin()]++;
                }
                else if(active==1)start=i;
                st.erase(x[i].second);
            }
        }
        cout<<"Case #"<<t<<": "<<sum-*max_element(ans.begin(),ans.end())<<endl;
    }
    return 0;
}

