#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int test;cin>>test;while(test--){
        int n,m,d,D;cin>>n>>m>>d>>D;
        vector<int>a(n,0),b(n,0),c(n);
        for(int i=0;i<n;i++)c[i]=i;
        unordered_map<int,unordered_set<int> >mp;
        int i=0;
        while(m--){
            mp[i].insert(c[i]);
            a[i]++;
            b[c[i]]++;
            c[i]++;
            c[i]%=n;
            i=(i+1)%n;
        }
        int flag=0;
        for(int i=0;i<n;i++){
            if(a[i]<d || a[i]>D || b[i]<d || b[i]>D)flag=1;
        }
        if(flag)cout<<"-1\n";
        else {
            for(auto &it:mp){
                for(auto &jt:it.ss) cout<<it.ff + 1<<" "<<jt + 1<<endl;
            }
        }
    }
    return 0;
}

