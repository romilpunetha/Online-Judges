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
typedef long long LL;
int a[1004] , b[1004] , c[1004];
LL segtree[40000] , arr[40000];
void build_tree(int node , int l , int r){
    if(l == r){
        segtree[node] = arr[l];
        return;
    }
    build_tree((2*node) , l , (l + r)/2);
    build_tree((2*node)+1 , (l+r)/2 + 1 , r);
    segtree[node] = min<LL >(segtree[(2*node)] , segtree[(2*node) + 1]);
}
int rangeQuery(int node , int l , int r , int al , int ar){
    if(l < 0)
        l = 0;
    if(r < 0)
        return INF;
    if((r < al) || (ar < l))
        return INF;
    if(l <= al && ar <= r)
        return segtree[node];
    int lmin , rmin;
    lmin = rangeQuery((2*node) , l , r , al , (al + ar)/2);
    rmin = rangeQuery(((2*node) + 1) , l , r , (al + ar)/2 + 1 , ar);
    return min<LL >(lmin , rmin);
}
int main(){
    int test;
    si(test);
    for(int o=1;o<=test;o++)
    {
        int n , m ,l;
        si(n);si(m);si(l);
        for(int i=1;i<=n;i++){
            si(a[i]);si(b[i]);si(c[i]);
        }
        for(int i=0;i<l+4;i++)
            arr[i] = INF;
        arr[0] = 0;
        for(int i=1;i<=n;i++){
            build_tree(1 , 0 , l);
            for(int j=0;j<=l;j++)
                arr[j] = min<LL >(arr[j] , rangeQuery(1 , j - b[i] , j - a[i] , 0 , l) + c[i] );
        }
        if(arr[l]<=m)
            printf("Case #%d: %lld\n", o , arr[l]);
        else
            printf("Case #%d: IMPOSSIBLE\n",o);
    }
    return 0;
}
