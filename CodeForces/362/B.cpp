#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;cin>>s;
    int e=0;
    while(s[e]!='e')e++;
    int a=stoi(s.substr(0,1));
    int b=stoi(s.substr(e+1));
    s=s.substr(2,e-2);
    int i=s.length()-1;
    while(i>=0 && s[i]=='0')i--;
    if(i<0)s="";
    if(a==0 && i<0){cout<<0<<endl;return 0;}
    cout<<a;
    int k=0;
    while(b){
        if(s[k])cout<<s[k++];
        else cout<<0;
        b--;
    }
    if(s[k])cout<<'.';
    while(s[k])cout<<s[k++];
    return 0;
}

