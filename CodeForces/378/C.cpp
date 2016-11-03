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
    int n; cin>>n;
    vector<int>arr(n), res(n,0);
    for(auto &it : arr) cin>> it;
    int m; cin>>m;
    vector<int>brr(m);
    for(auto &it : brr) cin>> it;
    stack<pair<int,char> >st;
    int i = 0, j = 0, mx = 0, mn = 12345678, curr = 0, reduce = 0, flag = 0 ;
    while(i < m){
        if(!mx) mx = arr[j], reduce = brr[i]-arr[j], curr = j++, mn = arr[j];
        else{
            if(reduce == 0){ mx = 0, mn = 0, i++, curr = i; continue; }
            else if(reduce < arr[j] || (reduce == 0 && mx == mn) ) {flag = 1; break;}
            reduce -= arr[j];
            mx = max(mx, arr[j]);
            mn = min(mn, arr[j]);
            if(arr[j] > arr[curr]) st.push({j,'L'}), curr = i;
            else st.push({curr, 'R'});
        }
        tr6(mx, mn, reduce, curr, i , j);
        j++;
    }
    if(flag) cout<<"NO\n";
    else{
        cout<<"YES\n";
        while(!st.empty()) {
            auto p = st.top();
            st.pop();
            cout<< p.ff<< " " << p.ss<<endl;
        }
    }
    return 0;
}



