#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int test;cin>>test;
    while(test--){
        string s;cin>>s;
        int flag=0;
        int len=s.length();
        for(int i=1;i<len;i++){
            int diff=abs(s[i]-s[i-1]);
            flag=(diff!=1 && diff!=25);
            if(flag)break;
        }
        cout<<(flag?"NO":"YES")<<endl;
    }
    return 0;
}

