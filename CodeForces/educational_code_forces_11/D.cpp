#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    unordered_map<double,unordered_map<double,int> > slope;
    slope.reserve((n*(n-1))/2);
    vector<pair<int,int> > points(n);
    for(int i=0;i<n;i++) cin>>points[i].first>>points[i].second;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int x1=points[i].first,x2=points[j].first,y1=points[i].second,y2=points[j].second;
            double len=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
            if(x1==x2)
            {
                slope[1][len]++;
            }
            else
            {
                double sl= (double)(points[j].second-points[i].second)/(points[j].first-points[i].first);
                slope[sl][len]++;
            }
        }
    }
    int ans=0;
    for(auto &it:slope)
    {
        for(auto &jt:it.second)
        {
            int p=jt.second;
            ans+=(p*(p-1))/2;
        }
    }
    cout<<ans/2<<endl;
    return 0;
}

