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
        string s;
        getline(cin,s);
        vector<string> arr;
        char *p=strtok(s.c_str()," ");
        while(p!=NULL){
            arr.push_back(string(p));
            p=strtok(NULL," ");
        }
        cout<<"Case #"<<t<<": ";
        for(int i=arr.size()-1;i>=0;i--) cout<<arr[i]<<" ";cout<<endl;
    }
    return 0;
}

