#include<stdio.h>
#include<stdlib.h>
struct Trie{
int leaf;
int index;
struct Trie *left,*right;
};
struct Trie * getNode(){
	struct Trie *trie=(struct Trie *)malloc(sizeof(struct Trie));
	
	return trie;
	}

void insert(int num,struct Trie *trie,int ii){
	int i=30;
		while(i>=0)
		{
			
			if((num&(1<<i))!=0)
			{
	//			printf("i1\n");
					if(trie->right==NULL)
					{
							trie->right=getNode();
					}
					
					trie=trie->right;
			}
			else
				{
					if(trie->left==NULL)
					{
							trie->left=getNode();
					}
					
					trie=trie->left;
				}
		i--;	
		}
		trie->index=ii;
	
	}
	int posr;
int	maxXOR(int data,struct Trie *trie){
	int sum=0;
	int i=30;
	while(i>=0){
		if((data&(1<<i))!=0&&trie->left!=NULL)
		{
		
			trie=trie->left;
				sum+=(1<<i);
		}
		else if((data&(1<<i))!=0&&trie->left==NULL)
		{
			
			trie=trie->right;
		}
		else if((data&(1<<i))==0&&trie->right!=NULL)
		{
			
			trie=trie->right;
				sum+=(1<<i);
		}
		else 
		{
			trie=trie->left;
		}
		i--;
		
		}
		 posr=trie->index;
		return sum;
		}
		
int main(){
	int n;
	scanf("%d",&n);
	struct Trie *trie=getNode();
	int xor=0,i=0;
	int a[n];
	int max1=0,maxpos=0;
	while(i<n)
	{
		int num;
		scanf("%d",&num);
		
		xor^=num;
		if(max1<xor)
			{max1=xor;maxpos=i;}
			//printf("mp%d\nxor%d\n",maxpos,xor);
		a[i]=xor;
		insert(xor,trie,i);
		
		i++;
	}
	
	int num,max=0,l=0,r=0;
	for(i=0;i<n;i++){
		
		num=maxXOR(a[i],trie);
		//printf("num%d\n",num);
		if(num>max)
			{max=num;
			l=i;
			r=posr;
		//	printf("r%d\n",r);
		}
		}
		if(max>max1)
			{
				printf("%d\n%d %d",max,l+2,r+1);
				
			}
			else
			printf("%d\n%d %d",max1,1,maxpos+1);
	return 0;
}
