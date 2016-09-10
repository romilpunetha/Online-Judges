#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
ll n,m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    ll t=n*n;
    set<int>x,y;
    for(int i=0;i<m;i++){
        int p,q;cin>>p>>q;
        if(x.find(p)==x.end() && y.find(q)==y.end()) {
            t-=(2*n - x.size()-y.size()-1);
        }
        else if(x.find(p)!=x.end() && y.find(q)!=y.end());
        else if(x.find(p)!=x.end()){
            t-=(n-x.size());
        }
        else t-=(n-y.size());
        cout<<t<<" ";
        x.insert(p);y.insert(q);
    }
    return 0;
}

