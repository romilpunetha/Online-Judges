#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int i=0;

int get(string &s){
    int num=0;
    while(s[i]>='0' && s[i]<='9')num=num*10+s[i]-'0',i++;
    return num;
}

string util(string &s){
    string t;
    while(s[i] && s[i]!=']'){
        while(s[i] && s[i]>='a' && s[i]<='z')t+=s[i++];
        if(!s[i] || s[i]==']')break;
        int lim=get(s);
        i++;
        string res=util(s),ret="";
        for(int i=0;i<lim;i++)ret+=res;
        t+=ret;
    }
    i++;
    return t;
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    string s;cin>>s;cout<<util(s)<<endl;
    return 0;
}

