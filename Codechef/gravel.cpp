#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int  n,m,c,u,v,p;
ll k;
char s;
ll bit[2000100];

void update(int ind,ll val){
    while(ind<=n){
        bit[ind]+=val;
        ind+=ind&-ind;
    }
}

ll query(int ind){
    ll sum=0;
    while(ind>0){
        sum+=bit[ind];
        ind-=ind&-ind;
    }
    return sum;
}

int main(){
    scanf(" %d %d %d",&n,&m,&c);
    memset(bit,0,sizeof(bit));
    for(int i=0;i<m;i++){
        scanf(" %c",&s);
        switch(s){
            case 'Q':{
                         scanf(" %d",&p);
                         printf("%lld\n",c+query(p));
                         break;
                     }
            case 'S':{
                         scanf(" %d %d %lld ",&u,&v,&k);
                         update(u,k);
                         update(v+1,-k);
                         break;
                     }
        }
    }
    return 0;
}

