#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int n;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    set<ll>st;
    for(int i=0;i<n;i++){ll t;cin>>t;st.insert(t);}
    if(st.size()<=2)return cout<<"YES",0;
    if(st.size()==3){
        auto it=st.begin();it++;
        if(*it-*st.begin()==*st.rbegin()-*it)return cout<<"YES",0;
    }
    cout<<"NO"<<endl;
    return 0;
}

