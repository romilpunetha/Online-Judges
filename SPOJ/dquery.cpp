#include<bits/stdc++.h>
#define N 311111
#define A 1111111
#define block_size 555
using namespace std;
typedef long long ll;
int res=0;
int counts[A];
int arr[N];
int answer[N];
typedef struct node/*{{{*/
{
    int l;
    int r;
    int pos;
}node;

void add(int pos)
{
    counts[arr[pos]]++;
    if(counts[arr[pos]]==1)
        res++;
}

void remove(int pos)
{
    counts[arr[pos]]--;
    if(counts[arr[pos]]==0)
        res--;
}
/*}}}*/
bool mo(node a,node b)/*{{{*/
{
    if(a.l/block_size < b.l/block_size)
        return true;
    else if(a.l/block_size == b.l/block_size && a.r<b.r)
        return true;
    return false;
}/*}}}*/

bool position(node a,node b)/*{{{*/
{
    return a.pos<b.pos;
}/*}}}*/

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int Q;
    scanf("%d ",&Q);
    vector<node> q(Q);
    for(int i=0;i<Q;i++)
    {
        scanf("%d %d",&q[i].l,&q[i].r);
        q[i].l--;
        q[i].r--;
        q[i].pos=i;
    }
    sort(q.begin(),q.end(),mo);
    int currentL=0,currentR=-1;/*}}}*/
    for(int i=0;i<Q;i++)
{
    while(currentL<q[i].l)
    {
        remove(currentL);
        currentL++;
    }
    while(currentL>q[i].l)
    {
        currentL--;
        add(currentL);
    }
    while(currentR<q[i].r)
    {
        currentR++;
        add(currentR);
    }
    while(currentR>q[i].r)
    {
        remove(currentR);
        currentR--;
    }
    answer[q[i].pos]=res;
}
for(int i=0;i<Q;i++)
{
    printf("%d\n",answer[i]);
}
return 0;
}

