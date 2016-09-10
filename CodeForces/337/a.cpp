#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    if(n<6 || n%2!=0){cout<<0<<endl;return 0;}
    cout<<(n/4 - ((n/2)%2==0))<<endl;
    return 0;
}

