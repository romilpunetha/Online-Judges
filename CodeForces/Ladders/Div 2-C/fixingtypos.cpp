#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int pre=0,i=0;
string s;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>s;
    while(s[i]){
        if(s[i]!=s[i+1])cout<<s[i++],pre=0;
        else if(!pre){
            pre=1;
            cout<<s[i]<<s[i+1];
            while(s[i]==s[i+1])i++;i++;
        }
        else{
            pre=0;
            cout<<s[i];
            while(s[i]==s[i+1])i++;i++;
        }
    }
    cout<<endl;
    return 0;
}

