#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int flag=0;

void display(vector<vector<char> >&A)/*{{{*/
{
    cout<<"sudoku : "<<endl;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}/*}}}*/

int box(int i,int j)/*{{{*/
{
    if(i>=0 && i<=2)
    {
        if(j>=0 && j<3)
            return 1;
        if(j>=3 && j<6)
            return 2;
        return 3;
    }
    if(i>=3 && i<=5)
    {
        if(j>=0 && j<3)
            return 4;
        if(j>=3 && j<6)
            return 5;
        return 6;
    }
    if(j>=0 && j<3)
        return 7;
    if(j>=3 && j<6)
        return 8;
    return 9;
}/*}}}*/

bool isvalidbox(vector<vector<char> >&A,int box,char a,int p,int q)/*{{{*/
{
    switch(box)/*{{{*/
    {
        case 1:for(int i=0;i<3;i++)
               {
                   for(int j=0;j<3;j++)
                   {
                       if(i==p && j==q)
                           continue;
                       if(A[i][j]==a)
                           return false;
                   }
               }
               break;
        case 2:for(int i=0;i<3;i++)
               {
                   for(int j=3;j<6;j++)
                   {
                       if(i==p && j==q)
                           continue;
                       if(A[i][j]==a)
                           return false;
                   }
               }
               break;
        case 3:for(int i=0;i<3;i++)
               {
                   for(int j=6;j<9;j++)
                   {
                       if(i==p && j==q)
                           continue;
                       if(A[i][j]==a)
                           return false;
                   }
               }
               break;
        case 4:for(int i=3;i<6;i++)
               {
                   for(int j=0;j<3;j++)
                   {
                       if(i==p && j==q)
                           continue;
                       if(A[i][j]==a)
                           return false;
                   }
               }
               break;
        case 5:for(int i=3;i<6;i++)
               {
                   for(int j=3;j<6;j++)
                   {
                       if(i==p && j==q)
                           continue;
                       if(A[i][j]==a)
                           return false;
                   }
               }
               break;
        case 6:for(int i=3;i<6;i++)
               {
                   for(int j=6;j<9;j++)
                   {
                       if(i==p && j==q)
                           continue;
                       if(A[i][j]==a)
                           return false;
                   }
               }
               break;
        case 7:for(int i=6;i<0;i++)
               {
                   for(int j=0;j<3;j++)
                   {
                       if(i==p && j==q)
                           continue;
                       if(A[i][j]==a)
                           return false;
                   }
               }
               break;
        case 8:for(int i=6;i<9;i++)
               {
                   for(int j=3;j<6;j++)
                   {
                       if(i==p && j==q)
                           continue;
                       if(A[i][j]==a)
                           return false;
                   }
               }
               break;
        case 9:for(int i=6;i<9;i++)
               {
                   for(int j=6;j<9;j++)
                   {
                       if(i==p && j==q)
                           continue;
                       if(A[i][j]==a)
                           return false;
                   }
               }
               break;
    }
    return true;/*}}}*/
}/*}}}*/

bool isvalidrow(vector<vector<char> >&A,char a,int p,int q)/*{{{*/
{
    for(int i=0;i<9;i++)
    {
        if(i==q)
            continue;
        if(A[p][i]==a)
            return false;
    }
    return true;
}/*}}}*/

bool isvalidcol(vector<vector<char> >&A,char a,int p,int q)/*{{{*/
{
    for(int i=0;i<9;i++)
    {
        if(i==p)
            continue;
        if(A[i][q]==a)
            return false;
    }
    return true;
}/*}}}*/

void util(vector<vector<char> >&A,int i,int j)
{
    if(flag)
        return;
    if(j==9)
    {
        flag=1;
        return;
    }
    if(A[i][j]!='.')
    {
        if(i+1==9)
        {
            //  cout<<"Calling at "<<i<<" "<<j+1<<endl;
            util(A,0,j+1);
        }
        else
        {
            //   cout<<"Calling at "<<i+1<<" "<<j<<endl;
            util(A,i+1,j);
        }
    }
    else
    {
        for(char c='1';c<='9';c++)
        {
            int b=box(i,j);
            //     cout<<"Checking "<<c<<" at "<<i<<" "<<j<<endl;
            if(isvalidrow(A,c,i,j) && isvalidcol(A,c,i,j) && isvalidbox(A,b,c,i,j))
            {
                cout<<"Putting "<<c<<" at "<<i<<" "<<j<<endl;
                A[i][j]=c;
                if(i+1==9)
                {
                    //  cout<<"Calling at "<<0<<" "<<j+1<<endl;
                    util(A,0,j+1);
                }
                else
                {
                    //  cout<<"Calling at "<<i+1<<" "<<j<<endl;
                    util(A,i+1,j);
                }
                if(flag==1)
                    return;
            }
        }
        cout<<"Removing "<<i<<" "<<j<<endl;
        A[i][j]='.';
    }
}

void solveSudoku(vector<vector<char> > &A) {
    flag=0;
    util(A,0,0);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<char> >A(9,vector<char>(9,' '));
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cin>>A[i][j];
        }
    }
    solveSudoku(A);
    display(A);
    return 0;
}

