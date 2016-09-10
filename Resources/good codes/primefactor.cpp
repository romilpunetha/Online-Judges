#include<iostream>
using namespace std;
 int primecheck(int);
 int main()
{
    int T;
    cout<<"enter the no of test cases"<<endl;
    cin>>T;
    while(T--)
    {
        int a,z;
               int i=2;
        cout<<"enter the no"<<endl;
        cin>>a;
        while(a!=1){
            z=primecheck(i);
            //cout<<"z"<<z<<endl;
            if(a%i==0&&z==1)
            {
                cout<<i<<" ";
                a=a/i;

            }
            else
            {
                i++;
             }

         }
          cout<<endl;
    }
    return 0;
    }

    int primecheck(int n)   //prime check code is imp
    {
    if(n==2)
    return 1;
    else{
    for(int i=2;i*i<=n;i++)
    {
    if(n%i==0)
    { cout<<"not prime"<<endl;
    return 0;
    }
    }

    return 1;
    }
    }

