#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unordered_set<char>st={'A','H','I','M','O','T','U','V','W','X','Y','o','v','w','x'};
    string s;cin>>s;
    int i=0,j=s.length()-1;
    while(i<j){
        if((st.find(s[i])!=st.end() && s[i]==s[j]) || (s[i]=='p' && s[j]=='q') || (s[i]=='q' && s[j]=='p') ||(s[i]=='b' && s[j]=='d') || (s[i]=='d' && s[j]=='b')){
            i++,j--;
        }
        else break;
    }
    if((i==j && st.find(s[i])!=st.end()) || (i>j)) cout<<"TAK"<<endl;
    else cout<<"NIE"<<endl;
    return 0;
}

