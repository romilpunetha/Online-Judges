#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,h,res=0;cin>>n>>h;
    while(n--){
        int temp;cin>>temp;res+=temp>h?2:1;
    }
    cout<<res;
    return 0;
}

