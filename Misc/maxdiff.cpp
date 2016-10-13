#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    set<int>st;
    ll diff=INT_MIN;
    for(int i=0;i<n;i++){
        int t;cin>>t;st.insert(t);
        diff=max(diff,(ll)*st.rbegin()-*st.begin());
    }
    cout<<diff<<endl;
    return 0;
}

