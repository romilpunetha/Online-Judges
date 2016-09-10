#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

vector<int>bit(1e6+10,0);

void update(int i){
    while(i<=1e6){
        bit[i]+=1;
        i+=i&-i;
    }
}

int query(int i){
    int sum=0;
    while(i){
        sum+=bit[i];
        i-=i&-i;
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    while(n--){
        int t;cin>>t;update(t);
    }
    int q;cin>>q;while(q--){
        int t;cin>>t;
        if(t>1e6)t=1e6;
        cout<<query(t)<<endl;
    }
    return 0;
}

