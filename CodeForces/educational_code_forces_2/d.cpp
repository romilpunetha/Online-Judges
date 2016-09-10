#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
long double x1,y1,r1,x2,y2,r2;
long double pi=3.14159265359;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<setprecision(20);
    cin>>x1>>y1>>r1>>x2>>y2>>r2;
    long double d=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    if(d>=r1+r2) return cout<<0.0<<endl,0;
    if(d<=max(r1,r2)-min(r1,r2)) return cout<<pi*min(r1,r2)*min(r1,r2)<<endl,0;
    long double d1= (r1*d)/(r1+r2);
    long double area11=0.5*d1*d1*tan(acos(d1/r1));
    long double area12=(pi*r1*r1*(acos(d1/r1)*180/pi))/360.0;
    long double res1=area12-area11;
    long double d2=(r2*d)/(r1+r2);
    long double area21=0.5*d2*d2*tan(acos(d2/r2));
    long double area22=(pi*r2*r2*(acos(d2/r2)*180/pi))/360.0;
    long double res2=area22-area21;
    cout<<res1+res2<<endl;
    return 0;
}

