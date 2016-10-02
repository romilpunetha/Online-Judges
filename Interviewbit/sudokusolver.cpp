#include <bits/stdc++.h>
using namespace std;

int flag=0;

int box(int i,int j){
    if(i>=0 && i<=2){
        if(j>=0 && j<3)
        return 1;
        if(j>=3 && j<6)
        return 2;
        return 3;
    }
       if(i>=3 && i<=5){
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
}

bool isvalidbox(vector<vector<char> >&A,int box,char a,int p,int q){
    switch(box){
        case 1:for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(i==p && j==q)
                continue;
                if(A[i][j]==a)
                return false;
            }
        }
        break;
        case 2:for(int i=0;i<3;i++){
            for(int j=3;j<6;j++){
                if(i==p && j==q)
                continue;
                if(A[i][j]==a)
                return false;
            }
        }
        break;
        case 3:for(int i=0;i<3;i++){
            for(int j=6;j<9;j++){
                if(i==p && j==q)
                continue;
                if(A[i][j]==a)
                return false;
            }
        }
        break;
        case 4:for(int i=3;i<6;i++){
            for(int j=0;j<3;j++){
                if(i==p && j==q)
                continue;
                if(A[i][j]==a)
                return false;
            }
        }
        break;
        case 5:for(int i=3;i<6;i++){
            for(int j=3;j<6;j++){
                if(i==p && j==q)
                continue;
                if(A[i][j]==a)
                return false;
            }
        }
        break;
        case 6:for(int i=3;i<6;i++){
            for(int j=6;j<9;j++){
                if(i==p && j==q)
                continue;
                if(A[i][j]==a)
                return false;
            }
        }
        break;
        case 7:for(int i=6;i<0;i++){
            for(int j=0;j<3;j++){
                if(i==p && j==q)
                continue;
                if(A[i][j]==a)
                return false;
            }
        }
        break;
        case 8:for(int i=6;i<9;i++){
            for(int j=3;j<6;j++){
                if(i==p && j==q)
                continue;
                if(A[i][j]==a)
                return false;
            }
        }
        break;
        case 9:for(int i=6;i<9;i++){
            for(int j=6;j<9;j++){
                if(i==p && j==q)
                continue;
                if(A[i][j]==a)
                return false;
            }
        }
        break;
    }
    return true;
}

bool isvalidrow(vector<vector<char> >&A,char a,int p,int q){
    for(int i=0;i<9;i++){
        if(i==q)
        continue;
        if(A[p][i]==a)
        return false;
    }
    return true;
}

bool isvalidcol(vector<vector<char> >&A,char a,int p,int q){
    for(int i=0;i<9;i++){
        if(i==p)
        continue;
        if(A[i][q]==a)
        return false;
    }
    return true;
}

void util(vector<vector<char> >&A,int i,int j){
    if(flag==1)
     return;
    if(j==9){
        flag=1;
        return;
    }
    if(A[i][j]!='.'){
        if(i+1==9){
            util(A,0,j+1);
        }
        else{
            util(A,i+1,j);
        }
    }
    else{
        for(char c='1';c<='9';c++){
            int b=box(i,j);
            if(isvalidrow(A,c,i,j) && isvalidcol(A,c,i,j) && isvalidbox(A,b,c,i,j)){
                A[i][j]=c;
                if(i+1==9){
                        util(A,0,j+1);
                    }
                else{
                        util(A,i+1,j);
                    }
                    if(flag==1)
                    return;
            }
        }
        A[i][j]='.';
    }
}

void solveSudoku(vector<vector<char> > &A) {
    flag=0;
    util(A,0,0);
}

int main() {
vector<vector<char> >arr(9,vector<char>(9));
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cin>>arr[i][j];
		}
	}
	solveSudoku(arr);
	for(auto &it:arr){
		for(auto &jt:it)cout<<jt<<" ";cout<<endl;
	}
	return 0;
}