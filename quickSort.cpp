#include"iostream"
#include"conio.h"
using namespace std;
void display(int array[],int size)
{   cout<<"\n\nThe array is:\n\n";
	for (int i=0;i<=size;i++)
	{
		cout<<"\t"<<array[i];
	}
}
int partition(int array[],int start,int end)
{
	int pindex=start;
	int pivot=array[end];
	for(int i=start;i<end;i++)
	{
		if (array[i]<pivot)
		{
			int temp;
			temp=array[i];
			array[i]=array[pindex];
			array[pindex]=temp;
			pindex++;	
					
		}
		cout<<"\n\n\nCHECK==\n\n\n";
		display(array,end);
	}
	
	int temp;
	temp=array[pindex];
	array[pindex]=array[end];
	array[end]=temp;
	return pindex;
}
void quickSort(int array[],int start,int end)
{
	if (start<end)
	{
		int pindex=partition(array,start,end);
		quickSort(array,start,pindex-1);
		quickSort(array,pindex+1,end);
		display(array,end);
	}
}

int main()
{
	int limit;
	int size=10;
	int array[size];
	cout<<"\nEnter size of the array you want to enter\t\t";
	cin>>limit;
	for (int i=0;i<limit;i++)
	{
		cin>>array[i];
	}
	display(array,limit-1);
	quickSort(array,0,limit-1);
	display(array,limit-1);
	return 0;
}
