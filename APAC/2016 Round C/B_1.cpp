#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
ll st = 0 , en = 1e16 , md , ans , K , per[104] , files[104];
ll x , y , ans1 , ans2;
bool valid(ll md){
    if(md == 0) return true;
    for(int i=1;i<=K;i++) {
        ll x = (files[i] * 100LL)/md;
        if(x!=per[i])return false;
    }
    return true;
}

int main(){
    int test;cin>> test;
    for(int o=1;o<=test;o++){
        cin>>K;
        st = 0,en = 1e16;
        for(int i=1;i<=K;i++) cin>>per[i]>>files[i];
        int grtr = 0 , lsr = 0 , eql = 0,flag = 1;
        ans = -1;
        while(st <= en){
            md = st + (en - st)/2;
            grtr = 0,lsr = 0,eql = 1;
            for(int i=1;i<=K;i++){
                x = (files[i] * 100LL)/md;
                if(x < per[i]) grtr = 1;
                else if(x > per[i]) lsr = 1;
                if(x!=per[i]) eql =0;
            }
            if(grtr == 1 || eql == 1){
                if(eql == 1) ans = md;
                en = md - 1;
            }
            else st = md + 1;
        }
        ans1 = ans,st = 0, en = 1e16;
        while(st <= en){
            md = st + (en - st)/2;
            grtr = 0,lsr = 0, eql = 1;
            for(int i=1;i<=K;i++){
                x = (files[i] * 100LL)/md;
                if(x < per[i]) grtr = 1;
                else if(x > per[i]) lsr = 1;
                if(x!=per[i]) eql = 0;
            }
            if(lsr == 1 || eql == 1){
                if(eql == 1) ans = md;
                st = md + 1;
            }
            else en = md - 1;
        }
        ans2 = ans;
        if(per[K] == 100)
            printf("Case #%d: %lld\n",o ,  files[K]);
        else{
            if(ans1==ans2) printf("Case #%d: %lld\n",o ,  ans1);
            else printf("Case #%d: -1\n",o);
        }
    }
    return 0;
}
