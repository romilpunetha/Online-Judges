#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int num;
    cin>>num;
    vector<int> arr(num);
    for(int i=0;i<num;i++)
    {
        cin>>arr[i];
    }
    for(int j=0;j<3;j++)
    {
        int i=j;
        long long int sum=0;
        while(i<num)
        {
            sum+=arr[i];
            i+=3;
        }
        cout<<sum<<" ";

    }
    cout<<endl;
    return 0;
}
