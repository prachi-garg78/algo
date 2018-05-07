#include"iostream"
#include"stdio.h"
#include"conio.h"
using namespace std;
	void maxHeapify(int index,int arr[],int size)
	{ cout<<"Check1\n";
		if(((2*index)+1)<size)
			{
			cout<<"Check2\n";
			if((arr[(2*index)+1]>arr[index])&&(arr[(2*index)+1]>arr[(2*index)+2]))
			{
				
			 int temp=arr[(2*index)+1];
			 arr[(2*index)+1]=arr[index];
			 arr[index]=temp;
			 maxheapify((index+1),arr,size);
			}
			else if((arr[(2*index)+2]>arr[index])&&(arr[(2*index)+2]>arr[(2*index)+1]))
			{ 
			 cout<<"check3\n";
			 int temp=arr[(2*index)+2]; 
			 arr[(2*index)+2]=arr[index];
			 arr[index]=temp;
			 maxheapify((index+2),arr,size);
			}
		}
	}
	
	void buildMax(int n,int arr[])
{
	 for (int i=n/2;i>=0;i--)
	{
 	maxheapify(i,arr,n);
 }
 void HeapIncreaseKey(int array[],int i, int key)
 {
 	if(key<array[i])
	{
		cout<<"The key is smaller than current key";
	}
	else
	{
		array[i]=key
		while(i>1&& (array[(i-1)/2]<array[i]))
		{
			int temp=array[i];
			array[i]=array[(i-1)/2];
			array[(i-1)/2]=temp;
		}
		i=(i-1)/2;
	}
}
void maxHeapInsert(int array[],int key)
{
	size=size+1;
	array[size]=
}
void heapExtractMax(int array[],int size)
{
	if(size<1)
	{
		cout<<"Heap unserflow";
	}
	int max=array[1];
	array[1]=array[size];
	size=size-1;
	maxHeapify(array,1,size);
	return max;	
}
int heapMaximum(int array[])
{
	return array[1];
}
int main()
{
	int array[]={18,7,5,4,9,3,1,2,8};
	int n=1;
	int size=9;
	cout<<"Heap Sort ";
	cout<<"\n\n\t\tEnter 1 to insert in heap\n";
	cout<<"\n\n\t\tEnter 2 to HeapSort\n";
	cout<<"\n\n\t\tEnter 3 to "
	buildMax(size,array);
	for (int i=0;i<9;i++)
	{
		cout<<array[i]<<"\t";
	}
}

}

