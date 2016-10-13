#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
#define ff first
#define ss second
using namespace std;
typedef long long ll;
int g,w,b,m,flag=0;

enum {Q,R,N,B};

int WW[4][2][2],BB[4][2][2];
int Q_x[]={1,2,3,-1,-2,-3,0,0,0,0,0,0,1,2,3,-1,-2,-3,1,2,3,-1,-2,-3};
int Q_y[]={0,0,0,0,0,0,1,2,3,-1,-2,-3,-1,-2,-3,1,2,3,1,2,3,-1,-2,-3};
int B_x[]={1,2,3,-1,-2,-3,1,2,3,-1,-2,-3};
int B_y[]={-1,-2,-3,1,2,3,1,2,3,-1,-2,-3};
int R_x[]={1,2,3,-1,-2,-3,0,0,0,0,0,0};
int R_y[]={0,0,0,0,0,0,1,2,3,-1,-2,-3};
int N_x[]={-1,1,-2,-2,-1,1,2,2};
int N_y[]={2,2,1,-1,-2,-2,-1,1};

bool isvalid(int i,int j){
    return (i>0 && i<=4 && j>0 && j<=4);
}

void util(int turn=0){
    if(flag==1)return;
    if(!(turn&1)){

    }
    else{

    }
}

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>g>>w>>b>>m;
    while(g--){
        flag=0;
        vector<vector<char> >arr(5,vector<char>(5,' '));
        char cc,dd,ee;
        while(w+b){
            cin>>cc>>dd>>ee;
            if(w){
                if(WW[cc][0][0])WW[cc][1][0]=ee-'0',WW[cc][1][1]=dd-'A'+1;
                else WW[cc][0][0]=ee-'0',WW[cc][0][1]=dd-'A'+1;
            }
            else{
                if(BB[cc][0][0])BB[cc][1][0]=ee-'0',BB[cc][1][1]=dd-'A'+1;
                else BB[cc][0][0]=ee-'0',BB[cc][0][1]=dd-'A'+1;
            }
            arr[ee-'0'][dd-'A'+1]=w?cc,w--:cc+32,b--;
        }
        util();
    }
    return 0;
}

