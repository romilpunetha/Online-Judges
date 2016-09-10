#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
int N,Q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    scanf(" %d %d ",&N,&Q);
    vector<pair<int,int> >arr(N);
    vector<int>res(N,0);
    for(int i=0;i<N;i++){
        int t;scanf(" %d",&t);arr[i]={i,t};
    }
    while(true){
        int lim=N;
        vector<pair<int,int> >temp;
        for(int i=0;i<lim;i+=2){
            if(i+1<lim){
                if(arr[i].second>arr[i+1].second)temp.push_back(arr[i]);
                else temp.push_back(arr[i+1]);
                res[arr[i].first]++,res[arr[i+1].first]++;
                N--;
            }
        }
        if(lim&1)temp.push_back(arr[lim-1]);
        swap(arr,temp);
        if(N==1)break;
    }
    while(Q--){
        int t;scanf(" %d",&t);t--;
        printf("%d\n",res[t]);
    }
    return 0;
}

