#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<int,int>row,col;
set<pair<int,int> >st;
int m,n,flag1=0,flag2=0,all0=1;

bool check(){
    for(auto &it:st){
        if(!(row[it.first]==n || col[it.second]==m)) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int a;cin>>a;
            if(a) row[i]++,col[j]++,st.insert({i,j}),all0=0;
            if(row[i]==n)flag1=1;
            if(col[j]==m)flag2=1;
        }
    }
    if(!check() || (!(flag1 && flag2) && !all0)) {cout<<"NO"<<endl;return 0;}
    cout<<"YES"<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(row[i]==n && col[j]==m) cout<<"1 ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
    return 0;
}

