#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
bool is_leap(int year){
    return ((year%400==0) || ((year%4==0)&&(year%100!=0)))?true:false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int year;cin>>year;
    int days=0,ans=year;
    while(1){
        if(ans>year && days%7==0 && is_leap(ans)==is_leap(year)){
            cout<<ans<<endl;break;
        }
        days+=is_leap(ans)?2:1;
        ans++;
    }
    return 0;
}

