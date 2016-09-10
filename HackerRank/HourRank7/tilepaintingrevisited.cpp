#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        int sum=0;
        for(int i=0;i<n-1;i++)
        {
            int terms= n/(i+1);
            sum+=(terms * (2+(terms-1)*(i+1)))/2;
        }
        cout<<sum<<endl;
    }
    return 0;
}
