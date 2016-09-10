#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
vector<int>arr(26,0);
string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    for(auto it:s) arr[it-'a']++;
    int i=0,j=25;
    while(i<j){
        if(arr[i]&1){
            while(j>i && arr[j]%2!=1) j--;
            if(i<j)arr[i]++,arr[j]--;
        }
        i++;
    }
    char mid=' ';
    for(i=0;i<26;i++){
        for(j=0;j<arr[i]/2;j++){
            cout<<(char)('a'+i);
        }
        if(arr[i]&1)mid=i+'a';
    }
    if(mid!=' ')cout<<mid;
    for(i=25;i>=0;i--){
        for(j=0;j<arr[i]/2;j++){
            cout<<(char)('a'+i);
        }
    }
    return 0;
}

