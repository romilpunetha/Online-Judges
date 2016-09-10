#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
string s,res1="\"",res2="\"";
int len;

bool is_num(string &p){
    if(p.size()==0) return false;
    if(p[0]=='0' && p[1]!='\0') return false;
    int i=0;
    while(p[i]!='\0' && p[i]>='0' && p[i]<='9') i++;
    return p[i]=='\0';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    len=s.size();
    int i=0,prev=0;
    int flag=0;
    while(i<len){
        while(i<len && s[i]!=',' && s[i]!=';') i++;
        string t=s.substr(prev,i-prev);
        if(is_num(t)) res1+=t+',';
        else res2+=t+',',flag=1;
        i++;
        prev=i;
    }
    string t="";
    if(prev<len){
        string t=s.substr(prev,i-prev);
        if(is_num(t)) res1+=t+',';
        else res2+=t+',';
    }
    if(s[len-1]==',' || s[len-1]==';') res2+=',',flag=1;
    res1.pop_back();res2.pop_back();
    res1+="\"";
    res2+="\"";
    if(res1.size()<=2) res1="-";
    if(res2.size()<=2 && !flag) res2="-";
    cout<<res1<<endl<<res2<<endl;
    return 0;
}

