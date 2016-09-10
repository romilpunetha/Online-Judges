#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;cin>>n>>m;
    set<ll>st;
    st.insert(1e10);
    st.insert(-1e10);
    vector<int>arr(n);
    for(auto &it:arr)cin>>it;
    for(int i=0;i<m;i++){
        int t;cin>>t;
        st.insert(t);
    }
    ll res=0;
    for(auto &it:arr){
        auto i=st.lower_bound(it);
        if(*i!=it)i--;
        auto j=st.upper_bound(it);
        res=max(res,min(abs(*i-it),abs(*j-it)));
    }
    cout<<res<<endl;
    return 0;
}

