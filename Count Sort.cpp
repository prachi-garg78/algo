using namespace std;
#include<iostream>
int maxno(int A[],int n)
{
	int large=A[0];
	for(int i=1;i<n;i++)
	{
		if(A[i]>large)
		large=A[i];
	}
	return large;
}

void countsort(int A[],int B[],int n,int d)
{
	int C[10];
	for(int i=0;i<10;i++)
	C[i]=0;
	for(int i=0;i<n;i++)
	{
		C[(A[i]/d)%10]++;
		
    }
    for(int j=1;j<10;j++)
    {
   	 C[j]=C[j]+C[j-1];
    }
    for(int j=n-1;j>=0;j--)
    {
   	 B[C[(A[j]/d)%10]-1]=A[j];
   	 C[(A[j]/d)%10]--;
    }
    cout<<"\n\n\t\t The array B is as follows :- ";
    for(int i=0;i<n;i++)
    cout<<B[i]<<"  ";
}
void radixsort(int A[],int n)
{
	int l=maxno(A,n);
	int d=1;
	int B[n];
	while(l/d > 0)
	{
		countsort(A,B,n,d);
		d*=10;
	}
	
	cout<<"\n\n\t\t The maximum element is :- "<<l;
	for(int i=0;i<n;i++)
	A[i]=B[i];
}
int main()
{
	int n;
	
	cout<<"\n\n\t\t Enter the size of the array :- ";
	cin>>n;
    int A[n];
	cout<<"\n\n\t\t Enter the array :- ";
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	radixsort(A,n);
	cout<<"\n\n\t\t The sorted array is as follows :-  ";
	for(int i=0;i<n;i++)
	cout<<A[i]<<"   ";
     cout<<"\n\n\t\t ";
	system("pause");
	return 0;
	
}
