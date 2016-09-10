#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int test,m,n,cnt,i;
multiset<int>st;
vector<int>ssum,res;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>test;while(test--){
        cin>>n;m=1<<n;
        st.clear();res.clear();ssum.clear();
        res.resize(n);
        for(i=0;i<m;i++){
            int t;cin>>t;st.insert(t);
        }
        st.erase(st.begin());
        i=0;while(!st.empty()){
            int t=ssum.size();
            for(int j=0;j<t;j++){
                st.erase(st.find(ssum[j]+*st.begin()));
                ssum.push_back(ssum[j]+*st.begin());
            }
            ssum.push_back(*st.begin());
            res[i++]=*st.begin();
            st.erase(st.begin());
        }
        for(auto &it:res)cout<<it<<" ";cout<<endl;
    }
    return 0;
}

