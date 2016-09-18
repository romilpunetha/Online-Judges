#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl
#define sol(x) cerr<<"Case : "<<x<<" solved!"<<endl
using namespace std;
typedef long long ll;

ll n,k,c,x,ans=0;
vector<vector<ll> >arr(3010,vector<ll>(3010));

ll getans(vector<ll>&c){
    deque<ll>q;
    ll an=0;
    for(int i=0;i<k;i++){
        while(!q.empty() && c[q.back()]<=c[i])q.pop_back();
        q.push_back(i);
    }
    for(int i=k;i<n;i++){
        an+=c[q.front()];
        while(!q.empty() && q.front()<=i-k) q.pop_front();
        while(!q.empty() && c[q.back()]<=c[i]) q.pop_back();
        q.push_back(i);
    }
    return an+=c[q.front()];
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int test;cin>>test;
    for(int tst=1;tst<=test;tst++){
        cin>>n>>k>>c>>x;
        ans=0;
        vector<ll>a(n),b(n),cc(n);
        vector<deque<ll> >q(n);
        for(auto &it:a)cin>>it; for(auto &it:b)cin>>it;
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) arr[i-1][j-1]=(a[i-1]*i + b[j-1]*j +c)%x;
        for(int i=0;i<n;i++){
            for(int j=0;j<k;j++){
                while(!q[i].empty() && arr[i][q[i].back()]<=arr[i][j]) q[i].pop_back();
                q[i].push_back(j);
            }
            cc[i]=arr[i][q[i].front()];
        }
        ans+=getans(cc);
        for(int j=k;j<n;j++){
            for(int i=0;i<n;i++){
                while(!q[i].empty() && q[i].front()<=j-k) q[i].pop_front();
                while(!q[i].empty() && arr[i][q[i].back()]<=arr[i][j]) q[i].pop_back();
                q[i].push_back(j);
                cc[i]=arr[i][q[i].front()];
            }
            ans+=getans(cc);
        }
        cout<<"Case #"<<tst<<": "<<ans<<endl;
        sol(tst);
    }
    return 0;
}

