#include<iostream>
using namespace std;
void quicksort(int *,int,int);
int parti(int *,int,int);
void swapp(int *,int *);
int main()
{
    int n;
    int start=0;
    int endd;
    cout<<"enter the no of terms"<<endl;
    cin>>n;
    endd=n;
    int A[n];
    cout<<"enter the nos "<<endl;
    for(int i=0;i<n;i++)
     cin>>A[i];
    for(int j=0;j<n;j++)
    cout<<A[j]<<" ";
    cout<<endl;
    quicksort(A,start,endd);
    for(int k=0;k<n;k++)
    cout<<A[k]<<" ";
    cout<<endl;
    return 0;
}
void quicksort(int *A,int start,int endd)
{

    int pIndex;
    if(start<endd)
    {
        pIndex=parti(A,start,endd);
        quicksort(A,start,pIndex-1);
        quicksort(A,pIndex+1,endd);
    }

}
int parti(int *A,int start,int endd)
{
        int pivot=A[endd];
        int pIndex=start;
        for(int i=start;i<endd;i++)
        {
        if(A[i]<=pivot)
        {
        swapp(&A[i],&A[pIndex]);
        pIndex=pIndex+1;
        }
        }
        swapp(&A[pIndex],&A[endd]);
        return pIndex;
}


void swapp(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

