#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
ll mod=1<<30;
ll ans=0;
vector<int>sieve(1001,1);
vector<int>primes;
unordered_map<int,int>mp;
void init(){
    for(int i=2;i<=1000;i++){
        if(sieve[i]){
            primes.push_back(i);
            for(int j=i+i;j<=1000;j+=i) sieve[j]=0;
        }
    }
}

int factors(int num){
    int f=1;
    if(mp.find(num)!=mp.end())return mp[num];
    int i=0,t=num;
    while(num>1){
        int res=0;
        while(num%primes[i]==0) {
            num/=primes[i];
            res++;
        }
        f=f*(res+1);
        i++;
    }
    mp[t]=f;
    return f;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    int a,b,c;cin>>a>>b>>c;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            for(int k=1;k<=c;k++){
                ans=(ans+factors(i*j*k))%mod;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

