#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,cnt=0;
vector<int>arr;

void util(int n){
    int num=0;
    while(n){
        num=0;
        for(int i=1000000;i>=1;i/=10){
            num=num*10 + !((n/i)%10==0);
        }
        cnt++;
        arr.push_back(num);
        n-=num;
    }
    cout<<cnt<<endl;
    for(auto it:arr) cout<<it<<" ";cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    util(n);
    return 0;
}

