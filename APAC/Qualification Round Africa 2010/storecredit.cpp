#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    for(int test=1;test<=n;test++){
        ll credit;cin>>credit;
        int size;cin>>size;
        vector<pair<int,int> >arr(size);
        for(int i=0;i<size;i++){
            int t;cin>>t;arr[i]={t,i+1};
        }
        sort(arr.begin(),arr.end());
        int i=0,j=size-1;
        while(1){
            if(arr[i].first+arr[j].first==credit){
                cout<<"Case #"<<test<<": "<<min(arr[i].second,arr[j].second)<<" "<<max(arr[j].second,arr[i].second)<<endl;
                break;
            }
            else if(arr[i].first+arr[j].first<credit) i++;
            else j--;
        }
    }
    return 0;
}

