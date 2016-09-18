#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

ll N , K , C , X , A[3004] , B[3004];
ll Rmax[3004][3004] , M[3004][3004] , Cmax[3004][3004];
ll ans = 0;
multiset<ll> S;
int main(){
    int test; cin>>test;
    for(int o=1;o<=test;o++){
        cin>>N>>K>>C>>X;
        for(ll i=1;i<=N;i++) cin>>A[i];
        for(ll i=1;i<=N;i++) cin>>B[i];
        for(ll i=1;i<=N;i++) for(int j=1;j<=N;j++) M[i][j] = ( ( (A[i]*i*1LL)%X + (B[j]*j*1LL)%X )%X + C)%X;
        multiset<ll >::iterator it;
        for(int i=1;i<=N;i++){
            S.clear();
            for(int j=1;j<=N;j++){
                S.insert(M[i][j]);
                if(j >= K){
                    it = S.end();
                    it--;
                    Rmax[i][j-K+1] = (*it);
                    S.erase(S.find(M[i][j-K + 1]));
                }
            }
        }
        for(int j=1;j<=N-K+1;j++){
            S.clear();
            for(int i=1;i<=N;i++){
                S.insert(Rmax[i][j]);
                if(i>=K){
                    it = S.end();
                    it--;
                    ans = ans + (*it);
                    S.erase(S.find(Rmax[i-K+1][j]));
                }
            }
        }
        printf("Case #%d: %lld\n", o , ans);
        ans = 0;
    }
    return 0;
}
