#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n,m;cin>>n>>m;
    int cnt=0;
    multiset<int>st={m,m,m};
    while(*st.begin()!=n){
        auto it=st.begin();it++;
        int x=*it-1+*st.rbegin();
        if(x>n)x=n;
        st.erase(st.begin());
        st.insert(x);
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}

