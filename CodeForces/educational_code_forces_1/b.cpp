#include<bits/stdc++.h>
using namespace std;
string s;
int l,r,k;
int main(){
    cin>>s;
    int n;cin>>n;
    while(n--){ cin>>l>>r>>k;
        k%=(r-l+1);
        rotate(s.begin()+l-1,s.begin()+r-k,s.begin()+r);
    }
    cout<<s<<endl;
    return 0;
}

