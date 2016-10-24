#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int test;cin>>test;
    for(int tt=1;tt<=test;tt++){
        string s;cin>>s;
        cout<<"Case #"<<tt<<": "<<s<<" is ruled by ";
        if(s[s.length()-1]=='y')cout<<"nobody.\n";
        else if(s[s.length()-1]=='a' || s[s.length()-1]=='e' || s[s.length()-1]=='i' || s[s.length()-1]=='o' || s[s.length()-1]=='u') cout<<"a queen.\n";
        else cout<<"a king.\n";
    }
    return 0;
}

