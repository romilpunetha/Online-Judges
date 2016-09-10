#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;cin>>s;
    int i=0,j=s.length()-1;
    while(i<=j && s[i]=='0')i++;
    while(j>=i && s[j]=='0')j--;
    if(i>j || (i==j && s[i]=='.')){cout<<"0"<<endl;return 0;}
    s=s.substr(i,j-i+1);
    int d=s.find('.');
    if(d<0)s+='.';
    int cnt=0;

    return 0;
}

