#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<map>
#include<algorithm>
#include<climits>

#define pb(n) push_back(n)
#define getMax(v) max_element(v.begin(),v.end())
#define getMin(v) min_element(v.begin(),v.end())

using namespace std;

bool canAliceWin(vector<int>& att,vector<int>& def,int maxA, int maxD, int n){
    int yy=0,yn=0,ny=0,nn=0;
    for(int i=0;i<n;i++){
        if(att[i]==maxA&&def[i]==maxD)
            return true;
        else if(att[i]<maxA&&def[i]==maxD)
            ny++;
        else if(att[i]==maxA&&def[i]<maxD)
            yn++;
        else
            nn++;
    }
    if(yy)
        return true;
    if(nn==0)
        return false;
    if(nn==1)
        return true;
    else{
        vector<int> attT;
        vector<int> defT;
        int maxAT = 0, maxDT= 0;
        for(int i=0;i<n;i++){
            if(att[i]<maxA&&def[i]<maxD){
                attT.pb(att[i]);
                defT.pb(def[i]);
                if(att[i]>maxAT)
                    maxAT = att[i];
                if(def[i]>maxDT)
                    maxDT = def[i];
            }
        }
        att.clear();
        def.clear();
        if(canAliceWin(attT,defT,maxAT,maxDT,attT.size()))
            return true;
        return false;
    }
    return false;
}

int main(){
	int t;
	cin>>t;
	int tc=1;
	while(t--){
        int n;
        cin>>n;
        vector<int> att;
        vector<int> def;
        int maxA = 0,maxD = 0;
        for(int i=0;i<n;i++){
            int a,d;
            cin>>a>>d;
            att.pb(a);
            def.pb(d);
            if(a>maxA)
                maxA=a;
            if(d>maxD)
                maxD=d;
        }
        if(canAliceWin(att,def,maxA,maxD,n))
            printf("Case #%d: YES\n",tc++);
        else
            printf("Case #%d: NO\n",tc++);
	}
	return 0;
}
