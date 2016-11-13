#include<bits/stdc++.h>
#define tr1(x)                cerr << #x << ":\t" << x << endl
#define tr2(x, y)             cerr << #x << ":\t" << x << "\t|\t" << #y << ":\t" << y << endl
#define tr3(x, y, z)          cerr << #x << ":\t" << x << "\t|\t" << #y << ":\t" << y << "\t|\t" << #z << ":\t" << z << endl
#define tr4(a, b, c, d)       cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << endl
#define tr5(a, b, c, d, e)    cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << "\t|\t" << #e << ":\t" << e << endl
#define tr6(a, b, c, d, e, f) cerr << #a << ":\t" << a << "\t|\t" << #b << ":\t" << b << "\t|\t" << #c << ":\t" << c << "\t|\t" << #d << ":\t" << d << "\t|\t" << #e << ":\t" << e << "\t|\t" << #f << ":\t" << f << endl
#define base 999983
#define baseinv 943912055
#define ff first
#define ss second
using namespace std;
typedef long long ll;

int n;
vector<int>arr;
vector<pair<int,int> >ed;

bool check(int start){
    int timer = 0;
    for(int j = 0; j < n; j++){
        if(arr[start] < timer) return false;
        timer++;
        start = (start + 1) % n;
    }
    return true;
}


int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n;
    arr = vector<int>(n);
    unordered_set<int> mp2;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(mp2.find(arr[i]) == mp2.end()) mp2.insert(arr[i]), ed.push_back({arr[i], i});
    }
    sort(ed.begin(), ed.end());
    int st = 0, endd = (int)ed.size() - 1;
    while(st < endd){
        int mid = (st + endd) >> 1;
        if(check( ed[mid].ss + 1 ) % n ) st = mid + 1;
        else endd = mid;
    }
    cout << ed[st].ss + 1 << endl;
    return 0;
}

