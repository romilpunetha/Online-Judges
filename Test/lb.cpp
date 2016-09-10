#include<bits/stdc++.h>
using namespace std;

map<int,int> m;

int main()
{
    m[10]=0;
    //auto l1=m.lower_bound(11);
    //map<int,int>::iterator b;
    auto b=m.lower_bound(4);
    if(b==m.end()) cout<<"hello"<<endl;
    //b++;
    //b++;
    //b++;
    //b++;
    cout<<b->first<<" "<<b->second<<endl;
    //auto r1=l1--;
    //cout<<"l : "<<l1->first<<" "<<l1->second<<endl;
    //cout<<"r : "<<r1->first<<" "<<r1->second<<endl;
    return 0;
}
