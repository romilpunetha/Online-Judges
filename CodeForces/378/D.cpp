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

typedef struct pipe{
    double l, b, h;
    double r;
    int id;
    pipe(){

    }
    pipe(double p, double q, double s,int idd){
        id = idd;
        vector<double> arr = {p, q, s};
        sort(arr.begin(), arr.end());
        l = arr[0], b = arr[1], h = arr[2];
        r = l / 2;
    }

}pipe;
map<pair<double, double>, set<pair<double,int> > >mp12, mp23, mp13;

pair<double,pair<int,int> > util(map<pair<double,double>, set<pair<double,int> > >&mp){
    double res = 0.0, mx = 0.0;
    pair<double,pair<int,int> > ans = {-1.0 , {-1,-1}};
    for(auto &it : mp){
        double l = it.ff.ff, b = it.ff.ss;
        auto &jt = it.ss;
        if(jt.size()>1){
            auto p = jt.rbegin();
            auto q = p++;
            double h = (*p).ff + (*q).ff;
            res = min(l, min(b,h)) / 2;
            if(mx <res)mx = res, ans = {mx , {(*p).ss, (*q).ss}};
        }
    }
    return ans;
}


int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n,ans = 1, k1 = 0, k2 = 0; cin>>n;
    double mx = 0.0;
    vector<pipe>arr(n);
    for(int i = 0; i < n; i++){
        double l, b, h; cin>> l >>b >> h;
        arr[i] = {l, b, h, i+1};
        if(arr[i].r > mx) mx = arr[i].r, k1 = i+1;
        mp12[{arr[i].l, arr[i].b}].insert({arr[i].h,i+1});
        mp23[{arr[i].b, arr[i].h}].insert({arr[i].l,i+1});
        mp13[{arr[i].l, arr[i].h}].insert({arr[i].b,i+1});
    }
    auto res1 = util(mp12), res2 = util(mp23), res3 = util(mp13);
    if(res1.ff > mx) ans = 2, mx = res1.ff, k1 = res1.ss.ff, k2 = res1.ss.ss;
    if(res2.ff > mx) ans = 2, mx = res2.ff, k1 = res2.ss.ff, k2 = res2.ss.ss;
    if(res3.ff > mx) ans = 2, mx = res3.ff, k1 = res3.ss.ff, k2 = res3.ss.ss;
    cout<<ans<<endl;
    if(ans == 1) cout<<k1<<endl;
    else cout<<min(k1,k2)<<" "<<max(k1,k2)<<endl;
    return 0;
}

