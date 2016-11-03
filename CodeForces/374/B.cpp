#include<bits/stdc++.h>
#define tr1(x)                cerr << #x << ":\t" << x << endl
#define tr2(x, y)             cerr << #x << ":\t" << x << "\t|\t" << #y << ":\t" << y << endl
#define tr3(x, y, z)          cerr << #x << ":\t" << x << "\t|\t" << #y << ":\t" << y << "\t|\t" << #z << ":\t" << z << endl
#define tr4(a, b, c, d)       cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << endl
#define tr5(a, b, c, d, e)    cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << "\t|\t" << #e << ":\t" << e << endl
#define tr6(a, b, c, d, e, f) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << "\t|\t" << #e << ":\t" << e << "\t|\t" << #f << ":\t" << f << endl
#define ff first
#define ss second
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n,k,best=0,worst=0;cin>>n>>k;
    map<int,int>mp;
    string s;
    while(n--){
        cin>>s;
        mp[s.length()]++;
    }
    cin>>s;
    int ans=s.length(),cnt=0;
    auto it=mp.begin();
    for(it=mp.begin(); it->ff<ans;){
        if(it->ss == 0) {it++; continue;}
        cnt++;
        best++;
        worst++;
        if(cnt == k) best += 5, worst += 5, cnt = 0;
        it->ss--;
    }
    best++;
    while(it->ss){
        cnt++;
        worst++;
        it->ss--;
        if(!it->ss) break;
        if(cnt == k) worst += 5, cnt=0;
    }
    cout<<best<<" "<<worst<<endl;
    return 0;
}

