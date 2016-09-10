#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
vector<string>arr;

bool is_Palin(const string &s,int start,int end){
    while(start<end){
        if(s[start]!=s[end]) return false;
        start++,end--;
    }
    return true;
}

typedef struct trie{
    typedef struct node{
        vector<node *>arr;
        vector<int>ind;
        bool eof;
        node(){
            arr.resize(26,NULL);
            eof=false;
        }
    }node;

    node *root;
    trie(){
        root=new node();
    }

    void insert(string &s,int ind){
        node *temp=root;
        int i=s.length()-1;
        while(i>=0){
            if(temp->arr[s[i]-'a']==NULL) {
                temp->arr[s[i]-'a']=new node();
            }
            temp=temp->arr[s[i]-'a'];
            temp->ind.push_back(ind);
            i--;
        }
        temp->eof=true;
    }

    void query(string &s,int res){
        node *temp=root;
        int i=0;
        while(s[i]!=NULL){
            if(temp->arr[s[i]-'a']==NULL) break;
            temp=temp->arr[s[i]-'a'];
            i++;
        }
        if(s[i]!=NULL && !temp->eof) return;
        if(s[i]==NULL){
            for(auto &it:temp->ind){
                if(it==res)continue;
                if(is_Palin(arr[it],0,arr[it].length()-1-i)){
                    cout<<res<<" "<<it<<endl;
                }
            }
        }
        else{
            if(is_Palin(s,i,s.length()-1)){
                for(auto &it:temp->ind) cout<<res<<" "<<it<<endl;
            }
        }
    }
}trie;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    trie A;
    int n;cin>>n;
    arr.resize(n);
    for(auto &it:arr)cin>>it;
    for(int i=0;i<n;i++)A.insert(arr[i],i);
    for(int i=0;i<n;i++)A.query(arr[i],i);
    return 0;
}

