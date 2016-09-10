#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int n,m;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    set<int>st;
    for(int i=0;i<n;i++){
        int t;cin>>t;
        for(int j=0;j<t;j++){
            int s;cin>>s;st.insert(s);
        }
    }
    if((int)st.size()==m)cout<<"YES";else cout<<"NO";
    return 0;
}

