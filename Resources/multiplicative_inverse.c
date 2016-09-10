#include<stdio.h>
#include<string.h>

int pow(int x,int y){
    long long mul=x;
    long long sum=1;
    while(y){
        if(y%2)
            sum=(sum*mul)%1000000007;
        mul=(mul*mul)%1000000007;
        y>>=1;
    }
    return (int)sum;
}

int inverse_prime(int a,int m) //if m is prime =a^m-2
{
    return pow(a,m-2);
}

int main()
{
    int M=1000000007;
    int t,k,i;
    scanf("%d",&t);
    while(t--){
        char c[1000000];
        scanf("%s %d",&c,&k);
        int l=strlen(c);
        long long b=pow(2,l);
        long long a=pow(b,k);
        int temp=(( (a-1)%M) * (inverse_prime((b-1) ,M) %M)%M); printf("temp%d ",temp);
        printf("%d ",temp);
        long sum=0;
        for(i=0;i<l;i++)
        {
            if(c[i]=='0' || c[i]=='5')
                sum=(sum+(pow(2,i)*temp)%M)%M;
        }
        printf("%ld\n",sum);

    }
}
