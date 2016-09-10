#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int n;
string s;
vector<string>ans;

void util(int pos,int diff){
    if(diff>n/2)return;
    if(pos==n && diff==n/2){ans.push_back(s);return;}
    if(pos>n)return;
    s.push_back('+');
    util(pos+1,diff);
    s.pop_back();
    s.push_back('*');
    util(pos+1,diff+1);
    s.pop_back();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    n=pow(2,n);
    util(0,0);
    for(int i=0;i<n-1;i++)cout<<ans[i]<<endl;
    for(int i=0;i<n;i++)cout<<'+';cout<<endl;
    return 0;
}

