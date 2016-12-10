#include<bits/stdc++.h>
#define endl '\n'
#define inf INT_MAX
#define pb push_back
#define present(c,x) ((c).find(x) != (c).end())
#define base 999983
#define baseinv 943912055
#define ff first
#define ss second
#define tr1(x)                cerr << #x << ": " << x << endl;
#define tr2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define tr3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define tr4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define tr5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define tr6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#define all(a) (a).begin(),(a).end()
using namespace std;
typedef long long ll;

string from, to;
int c, n, d1, d2;
unordered_map<int,int> dp;

int mnth[12] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
vector<pair<pair<int, int>, int>> arr;

int get_mnth(string &s){
    if(s == "Jan") return 0;
    if(s == "Feb") return 1;
    if(s == "Mar") return 2;
    if(s == "Apr") return 3;
    if(s == "May") return 4;
    if(s == "June") return 5;
    if(s == "July") return 6;
    if(s == "Aug") return 7;
    if(s == "Sept") return 8;
    if(s == "Oct") return 9;
    if(s == "Nov") return 10;
    if(s == "Dec") return 11;
    return -1;
}

int util(int st, int en, int cost){
    tr3(st, en, cost);
    if(st >= n) return cost;
    if(present(dp, st)) return dp[st];
    int ans = cost;
    for(int i = st; i < n; i++){
        if(arr[i].ff.ff >= en){
            ans = max(ans, util(i+1, arr[i].ff.ss, cost + arr[i].ss));
        }
    }
    return dp[st] = ans;
}


int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    for(int i = 1; i < 12; i++) mnth[i] += mnth[i - 1];
    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++){
        cin >> from >> d1 >> to >> d2 >> c;
        int st = mnth[get_mnth(from)] + d1, en = mnth[get_mnth(to)] + d2;
        arr[i].ss = c, arr[i].ff.ff = st, arr[i].ff.ss = en;
    }
    sort(all(arr));
    int ans = util(0, 0, 0);
    cout << ans << endl;
    return 0;
}

