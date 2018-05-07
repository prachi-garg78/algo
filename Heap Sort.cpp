using namespace std;
#include<iostream>
#include<fstream>
int k=0;
void max_heapify(int A[],int i,int n)
{
 int l=2*i;
 int r=2*i+1;
 int large=i;
 if(l<=n && A[l]>A[i])
	{
		
	  large=l;
	  k++;
	}

 if(r<=n && A[r]>A[large])
	{
	
	 large=r;
	 k++;
	 }


 if(large!=i)
 {
 	int temp=A[i];
	A[i]=A[large];
	A[large]=temp;
	max_heapify(A,large,n);
 }
}
void built_max_heap(int A[],int n)
{
  for(int i=n/2;i>=1;i--)
  {
  max_heapify(A,i,n);
  }
}
void heapsort(int A[],int n)
{
 built_max_heap(A,n);
 for(int i=n;i>=2;i--)
 {
  int temp=A[1];
		A[1]=A[i];
		A[i]=temp;
		n=n-1;
		max_heapify(A,1,n);
 }
}
int main()
{
	
	int n;
    cout<<"\n\n\t\t Enter the size of the array :- ";
    cin>>n;
    int a[n],b[n];
    cout<<"\n\n\t\t Enter the array  :-  ";
	for(int i=1;i<=n;i++)
	cin>>a[i];
	
	cout<<"\n\n\t\t The array is as follows :- ";
	for(int i=1;i<=n;i++)
	cout<<a[i]<<"  ";
    heapsort(a,n);
    cout<<"\n\n\t\t The sorted array is as follows :- ";
	for(int i=1;i<=n;i++)
	cout<<a[i]<<"  ";
	cout<<"\n\n\t\t The no. of comparisons are :- "<<k;
    cout<<"\n\n\t\t ";
    system("pause");
    return 0;
}
