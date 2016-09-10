#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int test,n,ki;
vector<ll>arr[4];
unordered_map<ll,ll>mp1,mp2;

void init(){
    mp1.clear();
    mp2.clear();
    for(int i=0;i<4;i++){
        arr[i].clear();
        arr[i].resize(n);
    }
}

typedef struct trie{

    typedef struct node{
        node *arr[2];
        int cnt=0;
        node(){
            arr[0]=NULL;
            arr[1]=NULL;
        }
    }node;

    node *root;
    trie(){
        root=new node();
    }

    void insert(int num,int val){
        node *temp=root;
        while(num){
            if(temp->arr[(num&1)]==NULL) {
                temp->arr[(num&1)]=new node();
            }
            temp=temp->arr[(num&1)];
            num>>=1;
        }
        temp->cnt=val;
    }

    int query(int num){
        node *temp=root;
        ll res=0;
        while(num){
            if(temp->arr[(num&1)]==NULL) return 0;
            temp=temp->arr[(num&1)];
            num>>=1;
        }
        res=temp->cnt;
        return res;
    }
}trie;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>test;
    for(int i=1;i<=test;i++){
        cin>>n>>ki;
        init();
        for(int j=0;j<4;j++){
            for(int k=0;k<n;k++){
                cin>>arr[j][k];
            }
        }
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                mp1[arr[0][j]^arr[1][k]]++;
                mp2[arr[2][j]^arr[3][k]]++;
            }
        }
        trie A;
        for(auto it:mp2){
            A.insert(it.first,it.second);
        }
        ll res=0;
        for(auto it:mp1) res+= it.second* A.query((it.first^ki));
        cout<<"Case #"<<i<<": "<<res<<endl;
    }
    return 0;
}

