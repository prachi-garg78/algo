using namespace std;
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
char B[10][20];
void lcs(string X,string Y,int m,int n)
{
	int L[m+1][n+1];
	
	
	for(int i=0;i<=m;i++)
	 L[i][0]=0;
	for(int j=0;j<=n;j++)
	 L[0][j]=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
		   if(X[i-1]==Y[j-1])
		  {
		  	L[i][j]=L[i-1][j-1]+1;
		  	B[i][j]='-';
		  }
		  else
		  if( L[i-1][j] >= L[i][j-1] )
		  {
		  	L[i][j]=L[i-1][j];
		  	B[i][j]='*';
		  }
		  else
		  {
		  	L[i][j]=L[i][j-1];
		  	B[i][j]='/';
		  }
		}  
    }
  
}
void print(string X,int i,int j)
{
	if(i==0 || j==0)
	return ;
	if(B[i][j]=='-')
	 { print(X,i-1,j-1);
	    cout<<X[i-1];
     }
	else
	if(B[i][j]=='*')
	  print(X,i-1,j);
	else
	if(B[i][j]=='/')
	  print(X,i,j-1);   
}
    
int main()
{
    string X,Y;
    cout<<"\n\n\t\t Enter the First string :-  ";
    getline(cin,X);
	cout<<"\n\n\t\t Enter the Second string :-  ";
    getline(cin,Y);
	int m=X.length();
	int n=Y.length();
	lcs(X,Y,m,n);
	cout<<"\n\n\t\t The longest common subsequence is :-  ";
	print(X,m,n);
	cout<<"\n\n\t\t   ";
	system("pause");	
    return 0;
}    

       
