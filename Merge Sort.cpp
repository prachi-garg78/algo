#include<fstream>
#include<iostream>
using namespace std;

int q=0;
void merge(int a[], int l,int m,int r);
void mergesort(int a[],int l,int r) // l is for left index and r is for right index
{
	if(l<r)
	{
		int m=(l+r)/2; 
		mergesort(a,l,m);
		mergesort(a,m+1,r);
		merge(a,l,m,r);
	}
}
void merge(int a[], int l,int m,int r) //function to merge two halves
{
	int i,j,k;
	int n1=m-l+1;
	int n2=r-m;
	int L[n1],R[n2]; // create temp. arrays
	for(i=0;i<n1;i++)
	L[i]=a[l+i];
	for(j=0;j<n2;j++)
	R[j]=a[m+1+j];
	i=0;
	j=0;
	k=l;
	while(i<n1 && j<n2)
	{
		if(L[i] <= R[j])
		{
			a[k]=L[i];
			i++;
			q++;
	    }
		else
		{
			a[k]=R[j];
			j++;
			q++;
		}
		k++;
	}
	while(i<n1)
	{
		a[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		a[k]=R[j];
		j++;
		k++;
	}
}
	
int main()
{
	ifstream f;
	f.open("average.txt");
	int i=0,j=0;
	int a[200],count=0,b[200];
	while(!f.eof())
	{
		f>>a[i];
		i++;
	}
    count=i-2;
	cout<<"\n\n\t\t The array is as follows :- ";
	for(i=0;i<count;i++)
	cout<<a[i]<<"  ";
	mergesort(a,0,count-1);
	cout<<"\n\n\t\t The sorted array is as fllows :- ";
	for(int i=0;i<count;i++)
	cout<<a[i]<<"  ";
	cout<<"\n\n\t\t The total no of comparisons are :-  "<<q;
    f.close();
	cout<<"\n\n\t\t ";
	system("pause");
	return 0;
	
}
