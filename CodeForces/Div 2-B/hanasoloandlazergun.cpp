#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,x,y;
unordered_set<double>st;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>x>>y;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        if(a==x)st.insert(DBL_MAX);
        else st.insert(((double)b-y)/((double)a-x));
    }
    cout<<st.size()<<endl;
    return 0;
}

