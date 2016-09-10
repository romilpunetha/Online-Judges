#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    for(cin>>test;test--;){
        int n;cin>>n;
        char a='a';
        for(int i=0;i<n;i++){
            cout<<a;
            if(a=='z') a='a';
            else a++;
        }
        cout<<endl;
    }
    return 0;
}

