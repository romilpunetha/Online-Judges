#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

ll n=0,m=0,bx=0,by=0,x=0,y=0,ans1=0,ans2=0;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>bx;
    for(int i=0;i<n;i++){
        cin>>x;
        ans1=ans1*bx+x;
    }
    cin>>m>>by;
    for(int i=0;i<m;i++){
        cin>>y;
        ans2=ans2*by+y;
    }
    if(ans1==ans2)cout<<"=";
    else if(ans1<ans2)cout<<"<";
    else cout<<">";
    cout<<endl;
    return 0;
}
