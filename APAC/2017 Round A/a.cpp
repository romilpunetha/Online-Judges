#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;cin>>test;
    cin.ignore();
    for(int t=1;t<=test;t++){
        cout<<"Case #"<<t<<": ";
        int no;cin>>no;
        cin.ignore();
        vector<set<char> >arr(no);
        vector<string>st(no);
        int mx=0;
        for(int i=0;i<no;i++){
            getline(cin,st[i]);
            for(auto &it:st[i]) if(it!=' ')arr[i].insert(it);
            mx=max(mx,(int)arr[i].size());
        }
        int ans=-1;
        for(int i=0;i<no;i++){
            if((int)arr[i].size()==mx){
                if(ans==-1) ans=i;
                else{
                    ans=st[ans]<st[i]?ans:i;
                }
            }
        }
        //whats(ans);
        cout<<st[ans]<<endl;
    }
    return 0;
}

