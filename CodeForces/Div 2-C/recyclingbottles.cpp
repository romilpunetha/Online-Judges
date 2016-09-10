#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

double sum=0.0,res=0.0;
int x1,y1,x2,y2,bx,by,px,py;

long double dist(int x11,int y11,int x22,int y22){
    return sqrt(pow(x11-x22,2)+ pow(y11-y22,2));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>x1>>y1>>x2>>y2>>bx>>by>>n;
    long double l=0.0;
    //long double l=1e18;
    long double profitAB=l,profitA=l,profitB=l;
    for(int i=0;i<n;i++){
        cin>>px>>py;
        sum+=2*dist(px,py,bx,by);
        long double bin=dist(px,py,bx,by),A=dist(px,py,x1,y1),B=dist(px,py,x2,y2);
        long double pa=A-bin,pb=B-bin;
        profitAB=i!=0?min(profitAB,min(profitA+pb,profitB+pa)):min(profitA+pb,profitB+pa);
        profitA=i!=0?min(profitA,pa):pa;
        profitB=i!=0?min(profitB,pb):pb;
        //profitAB=min(profitAB,min(profitA+pb,profitB+pa));
        //profitA=min(profitA,pa);
        //profitB=min(profitB,pb);
    }
    cout<<fixed<<setprecision(18)<<sum+min(profitAB,min(profitA,profitB))<<endl;
    return 0;
}

