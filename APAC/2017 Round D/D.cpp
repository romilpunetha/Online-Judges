#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int test;cin>>test;
    for(int tt=1;tt<=test;tt++){
        int n,m,l;
        cin>>n>>m>>l;
        vector<ll>a(1e5,INT_MAX),b(1e5,INT_MAX),p(1010),q(1010),c(1010);
        for(int i=0;i<n;i++)cin>>p[i]>>q[i]>>c[i];
        for(int i=0;i<n;i++){
            for(int j=0;j<=l;j++){
                if(j+p[i]<1e5) b[j+p[i]]=min(b[j+p[i]],min(a[j]+c[i],(ll)INT_MAX));
                else break;
                if(j+q[i]<1e5){
                    b[j+q[i]]=min(abs(b[j+q[i]]),min(a[j]+c[i],(ll)INT_MAX));
                    b[j+q[i]+1]=-min(abs(b[j+q[i]+1]),(ll)INT_MAX);
                }
            }
            for(int j=0;j<=l;j++)b[j]=min(b[j],a[j]),a[j]=INT_MAX;
            for(int j=p[i];j<=q[i];j++) b[j]=min(b[j],c[i]);
            for(auto it=0;it<=l;it++) cout<<it<<" "<<b[it]<<endl;
            swap(a,b);
        }
        whats(a[l]);
        cout<<"Case #"<<tt<<": "<<(a[l]<=m?to_string(a[l]):"IMPOSSIBLE")<<endl;
    }
    return 0;
}
