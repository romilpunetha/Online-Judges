#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,min_x=INT_MAX,min_y=INT_MAX,max_x=0,max_y=0;cin>>n;
    if(n==1){return cout<<"NO",0;}
    string num;cin>>num;
    int i=0;
    while(num[i]){
        int t=num[i++]-'0';
        if(t==0) max_x=3,max_y=max(max_y,1),min_x=min(min_x,3),min_y=min(min_y,1);
        else{
            min_x=min(min_x,(t-1)/3);
            min_y=min(min_y,(t-1)%3);
            max_x=max(max_x,(t-1)/3);
            max_y=max(max_y,(t-1)%3);
        }
    }
    int area=(max_x-min_x+1) * (max_y-min_y+1);
    if(area>=9 || (max_x-min_x==3) ) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}

