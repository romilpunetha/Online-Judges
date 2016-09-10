#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
unsigned int mod=1e9+7;
ll prime=193;
vector<pair<int,ll> > arr;
vector<ll>primes;
int l;
string s;

void init (){
    for(int i=1;i<l;i++){
        primes[i]=(primes[i-1]*prime)%mod;
    }
}

void inc_hash(){
    ll prehash=0,sufhash=0;
    for(int i=0;i<l-1;i++){
        prehash+=s[i]*primes[i];
        sufhash=sufhash*prime+s[l-i-1];
        if(prehash==sufhash) arr.push_back({i+1,prehash});
    }
}

ll hashs(int start,int end){
    ll newhash=0;
    for(int i=start;i<=end;i++){
        newhash+=s[i]*primes[i-start];
    }
    return  newhash;
}

ll rehash(ll oldhash,int oval,int nval){
    ll newhash=oldhash-s[oval];
    whats(newhash%prime);
    newhash/=prime;
    newhash+=(s[nval]*primes[nval-oval-1]);
    return newhash;
}

bool is_found(const pair<int,ll> &len){
    ll prehash=hashs(1,len.first);
    whats(len.second);
    for(int i=1;i<l-len.first;i++){
        if(prehash==len.second ) return true;
        prehash=rehash(prehash,i,len.first+i);
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    l=s.length();
    primes=vector<ll>(l,1);
    init();
    inc_hash();
    int start=0,end=arr.size()-1,size=0;
    while(start<=end){
        int mid= start+ ((end-start)>>1);
        whats(mid);
        if(is_found(arr[mid])) size=arr[mid].first,start=mid+1;
        else end=mid-1;
    }
    cout<<(size==0?"Just a legend":s.substr(0,size))<<endl;
    return 0;
}

