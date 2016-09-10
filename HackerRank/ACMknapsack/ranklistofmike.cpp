#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int bs;
typedef struct node
{
    int l;
    int r;
    int i;
    int k;
    ll ans;
    bool operator<(const node &n) const {
        if(this->l==n.l && this->r == n.r && this->k==n.k)
            return false;
        return this->i<n.i;
    }
}node;
map<ll,int>m;
vector<ll>arr;
vector<ll>ans;
vector<node>q;
map<node,ll> m2;

void display()
{
    cout<<endl<<"Map contains:"<<endl;
    for(auto it=m.begin();it!=m.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
    cout<<endl<<endl;
}

void add(int pos)
{
    m[arr[pos]]++;
}

void remove(int pos)
{
    m[arr[pos]]--;
}


bool mo(node &a,node &b)
{
    if(a.l/bs < b.l/bs)
        return true;
    else if(a.l/bs == b.l/bs)
        return a.r<b.r;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    scanf("%d ",&N);
    bs=sqrt(N);
    arr.resize(N);
    for(int i=0;i<N;i++)
    {
        scanf("%lld ",&arr[i]);
    }
    int Q;
    scanf("%d ",&Q);
    q.resize(Q);
    ans.resize(Q);
    for(int i=0;i<Q;i++)
    {
        scanf("%d %d %d",&(q[i].l),&(q[i].r),&(q[i].k));
        q[i].l--;
        q[i].r--;
        q[i].i=i;
    }
    sort(q.begin(),q.end(),mo);
    int currentL=0,currentR=-1;
    for(int i=0;i<Q;i++)
    {
        if(m2[q[i]]!=0)
        {
            //cout<<"Repeated query : "<<i<<endl;
            ans[q[i].i]=m2[q[i]];
            continue;
        }
        else
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
            //display();
            auto itr=m.begin();
            while(itr!=m.end())
            {
                if(!itr->second)
                {
                    itr= m.erase(itr);
                }
                else
                    itr++;
            }
            //display();
            auto it=m.rbegin();
            for(;it!=m.rend();it++)
            {
                q[i].k--;
                if(!q[i].k)
                    break;
            }
            if(!q[i].k)
                ans[q[i].i]=it->first;
            else
                ans[q[i].i]=-1;
            m2[q[i]]=ans[q[i].i];
        }
    }
    for(int i=0;i<Q;i++)
    {
        printf("%lld\n",ans[i]);
    }
    return 0;
}

