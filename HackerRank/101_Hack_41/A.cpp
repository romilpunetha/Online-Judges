#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n,k;
    cin>>n>>k;
    char c;
    unordered_set<int>st;
    for(int i=1;i<=n;i++){
        cin>>c;
        if(c-'0')st.insert(i);
    }
    bool flag=1;
    while(k-- && flag){
        int t;cin>>t;
        flag=st.find(t)!=st.end();
    }
    if(flag)cout<<"NO\n";
    else cout<<"YES\n";
    return 0;
}

