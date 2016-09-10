#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i=0,j=0,row=0,col=0;string s;cin>>n>>s;
    s+=',';
    vector<vector<int> >arr(n,vector<int>(n,0));
    while(row<n){
        col=0;
        while(!(s[i]==')' && s[i+1]==','))i++;
        while(j<i){
            j++;
            string num="";
            while(j<i && s[j]!=',') num+=s[j++];
            arr[row][col++]=atoi(num.c_str());
            num.clear();
        }
        row++;
        i++;
        j=i+1;
    }
    for(auto it:arr){
        for(auto jt:it)cout<<jt<<" ";cout<<endl;
    }
    return 0;
}

