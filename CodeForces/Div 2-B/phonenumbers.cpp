#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

bool is_taxi(string s){
    int i=-1;
    char c=s[0];
    while(s[++i]!='\0'){
        if(s[i]=='-')continue;
        if(s[i]!=c) return false;
    }
    return true;
}

bool is_pizza(string s){
    char c=s[0];
    int i =0;
    while(s[++i]!='\0'){
        if(s[i]=='-')continue;
        if(s[i]>=c) return false;
        c=s[i];
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    string name[n];
    vector<vector<int> >detail(3,vector<int>(n,0));
    for(int i=0;i<n;i++){
        int cnt;cin>>cnt;cin>>name[i];
        while(cnt--){
            string s;cin>>s;
            if(is_taxi(s)) detail[0][i]++;
            else if(is_pizza(s))detail[1][i]++;
            else detail[2][i]++;
        }
    }
    int taxi=*max_element(detail[0].begin(),detail[0].end());
    int c_taxi=count(detail[0].begin(),detail[0].end(),taxi);
    int pizza=*max_element(detail[1].begin(),detail[1].end());
    int c_pizza=count(detail[1].begin(),detail[1].end(),pizza);
    int girl=*max_element(detail[2].begin(),detail[2].end());
    int c_girl=count(detail[2].begin(),detail[2].end(),girl);
    cout<<"If you want to call a taxi, you should call:";
    for(int i=0;i<n;i++){
        if(detail[0][i]==taxi) {
            cout<<" "<<name[i];c_taxi--;
            if(c_taxi)cout<<",";
            else cout<<"."<<endl;
        }
    }
    cout<<"If you want to order a pizza, you should call:";
    for(int i=0;i<n;i++){
        if(detail[1][i]==pizza) {
            cout<<" "<<name[i];c_pizza--;
            if(c_pizza)cout<<",";
            else cout<<"."<<endl;
        }
    }
    cout<<"If you want to go to a cafe with a wonderful girl, you should call:";
    for(int i=0;i<n;i++){
        if(detail[2][i]==girl) {
            cout<<" "<<name[i];c_girl--;
            if(c_girl)cout<<",";
            else cout<<"."<<endl;
        }
    }
    return 0;
}

