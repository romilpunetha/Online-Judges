
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
typedef long long int LL;
int main()
{
    std::ios::sync_with_stdio(false);
    LL N , D ;
    int test;
    si(test);
    LL R , max_k , min_k , ans = 0 , R1;
    LL st = 0 , en = INF_LL , md;
    for(int o=1;o<=test;o++)
    {
        slli(N);slli(D);
        ans = 0;
        for(LL pst = D;pst<=N;pst+=D)
        {
            for(LL A=1 ; (pst*A*1LL)<= N ; A++)
            {
                R = N - (pst * A *1LL) ;
                R1 = R*(pst + 3LL);
                st = 0;
                en = (INF_LL/(pst+2LL));
                while(st <= en)
                {
                    md = (st + (en - st)/2LL);

                    if((md*(pst + 2LL)) >= R1)
                    {
                        min_k = md;
                        en = md - 1;
                    }
                    else
                        st = md + 1;
                }
                R1 = R*(pst + 2LL);
                st = 0;
                en = (INF_LL/(pst + 1LL));
                while(st <= en)
                {
                    md = (st + (en - st)/2LL);

                    if((md*(pst + 1LL)) <= R1)
                    {
                        max_k = md;
                        st = md + 1;
                    }
                    else
                        en = md - 1;
                }
                ans = ans + (max_k - min_k + 1);
            }
        }
        printf("Case #%d: %lld\n", o , ans);
    }
    return 0;
}
