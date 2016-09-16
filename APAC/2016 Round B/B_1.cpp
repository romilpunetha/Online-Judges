#include<bits/stdc++.h>
#define whats(x) cerr << #x << " is " << x << endl;
using namespace std;
typedef long long ll;
ll a[2004] , b[2004] , c[2004] , Np , Nt , Ne , P , Q;
bool valid[10004][10004];
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int test;
    cin>>test;
    for(int o=1;o<=test;o++){
        cin>>Np>>Ne>>Nt;
        for(int i=1;i<=Np;i++)
            cin>>a[i];
        for(int i=1;i<=Ne;i++)
            cin>>b[i];
        ll x , y , g;
        memset(valid , false , sizeof(valid));
        for(int i=1;i<=Ne;i++){
            for(int j=i+1;j<=Ne;j++){
                x = b[i];
                y = b[j];
                g = __gcd(x , y);
                x = (x / g);
                y = (y / g);
                valid[x][y] = true;
                valid[y][x] = true;
            }
        }
        for(int i=1;i<=Nt;i++)cin>>c[i];
        int flag = 0 , q;
        cin>>q;
        printf("Case #%d:\n", o);
        while(q--)
        {
            cin>>P>>Q;
            flag = 0;
            for(int i=1;i<=Np && flag == 0;i++)
            {
                for(int j=1;j<=Nt && flag == 0;j++)
                {
                    x = P*c[j];
                    y = Q*a[i];
                    g = __gcd(x , y);
                    x = (x / g);
                    y = (y / g);
                    if(x<=10000 && y<=10000)
                        if(valid[x][y] == true)
                            flag = 1;
                }
            }
            if(flag == 0)
                printf("No\n");
            else
                printf("Yes\n");
        }
    }
    return 0;
}
