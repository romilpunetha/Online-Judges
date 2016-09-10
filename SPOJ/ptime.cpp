#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
vector<bool>sieve(100100,1);
vector<int>prime;
vector<int>ans;

void get_Primes(){
    for(int i=2;i<100100;i++){
        if(sieve[i]){
            prime.push_back(i);
            for(int j=2*i;j<100100;j+=i){
                sieve[j]=false;
            }
        }
    }
}

void get(int a){
    while(a>1){
        for(auto &it:prime) {
            while(a%it==0)ans[it]++,a/=it;
            if(a==1) return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    get_Primes();
    int num;cin>>num;
    ans.resize(100010,0);
    for(int i=2;i<=num;i++) get(i);
    bool flag=0;
    for(int i=0;i<=num;i++){
        if(ans[i] && !flag) cout<<i<<"^"<<ans[i],flag=1;
        else if(ans[i]) cout<<" * "<<i<<"^"<<ans[i];
    }
    cout<<endl;
    return 0;
}

