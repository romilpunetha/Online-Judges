#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int size;
    cin>>size;
    map<int,int>m;
    m[0]=m[1<<30]=0;
    for(int i=0;i<size;i++)
    {
        int temp;
        cin>>temp;
        auto l=m.lower_bound(temp);
        auto r=l--;
        cout<<"l : "<<l->first<<" "<<l->second<<endl;
        cout<<"r : "<<r->first<<" "<<r->second<<endl;
        auto s=l->second>r->second?l:r;
        if(i) cout<<s->first<<" ";
        m[temp]=s->second+1;
    }
    return 0;
}

