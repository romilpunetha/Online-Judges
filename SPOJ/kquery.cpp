#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
typedef struct qry{
    int l,r,k,pos;
}qry;

typedef struct pr{
    int val,pos;
}pr;
int size,i;
int bit[30001];

void update(int ind,int val){
    while(ind<=size){
        bit[ind]+=val;
        ind+=ind&-ind;
    }
}

int query(int ind){
    int sum=0;
    while(ind>0){
        sum+=bit[ind];
        ind-=ind&-ind;
    }
    return sum;
}

int main(){
    scanf("%d ",&size);
    pr arr[size];
    for(i=0;i<size;i++) scanf("%d ",&arr[i].val),arr[i].pos=i+1;
    sort(arr,arr+size,[](const auto &a,const auto &b){return a.val>b.val;});
    int q;scanf("%d ",&q);
    qry arr2[q];
    for(i=0;i<q;i++) scanf("%d %d %d ",&arr2[i].l,&arr2[i].r,&arr2[i].k),arr2[i].pos=i;
    sort(arr2,arr2+q,[](const auto &a,const auto &b){return a.k>b.k;});
    int p=0;
    int ans[q];
    for(i=0;i<q;i++){
        while(p<size && arr[p].val>arr2[i].k){
            update(arr[p].pos,1);
            p++;
        }
        ans[arr2[i].pos]=query(arr2[i].r)-query(arr2[i].l-1);
    }
    for(i=0;i<q;i++) printf("%d\n",ans[i]);
    return 0;
}

