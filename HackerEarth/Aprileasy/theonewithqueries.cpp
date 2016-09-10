#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<list>
#include<unordered_map>
using namespace std;

bool util(vector<list<int> >&vlist,string &t)
{
    list<int>::iterator it[26];
    for(int i=0;i<26;i++)
    {
        it[i]=vlist[i].begin();
    }
    int l=t.length();
    int curr=0,flag=0;
    for(int i=0;i<l;i++)
    {
        while(it[t[i]-'a']!=vlist[t[i]-'a'].end() && curr>*it[t[i]-'a'])
        {
            it[t[i]-'a']++;
        }
        if(it[t[i]-'a']==vlist[t[i]-'a'].end())
        {
            flag=1;
            break;
        }
        curr=*it[t[i]-'a'];
    }
    if(!flag)
        return true;
    return false;

}

int main()
{
    string s;
    cin>>s;
    vector<list<int> > vlist(26);
    int l=s.length();
    for(int i=0;i<l;i++)
    {
        vlist[s[i]-'a'].push_back(i+1);
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        string temp;
        cin>>temp;
        bool test=util(vlist,temp);
        if(test)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
