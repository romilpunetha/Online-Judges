#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;cin>>test;
    while(test--){
        unordered_set<string>st;
        string s;cin>>s;
        for(int i=1;i<=(int)s.length();i++){
            for(int j=0;j+i<=(int)s.length();j++){
                st.insert(s.substr(j,i));
            }
        }
        cout<<st.size()<<endl;
    }
    return 0;
}

