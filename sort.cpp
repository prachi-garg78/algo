#include"iostream"
#include"conio.h"
using namespace std;
class sort
{
	int size;
	int array[100];
public:	void input();
	void display();
	void bubbleSort();
	void selectionSort();
	void insertionSort();
};
void sort::selectionSort()
{
	for(int i=0;i<size;i++)
	{
		int temp;
		int min=array[i];
		for (int j=i+1;j<size;j++)
		{
			
			if(array[j]<min)
			{
				temp=array[i];
				array[i]=array[j];
				array[j]=temp;
			}
		}
	}
	display();
}
void sort::bubbleSort()
{
	int temp;
	for (int i=0;i<size;i++)
	{
		for (int j=0;j<size-i-1;j++)
		{
			if (array[j]>array[j+1])
			{
			 temp=array[j];
			 array[j]=array[j+1];
			 array[j+1]=temp;
			}
		}
	}
	display();
}
void sort::insertionSort()
{
	int temp;
	for (int i=1;i<size;i++)
	{
		temp=array[i];
		int j=i-1;
		while(j>=0 && temp<array[j])
		{
			array[j+1]=array[j];
			j--;
		}
			array[j+1]=temp;
	}
		
	display();
}
void sort::input()
{
	system("CLS");
	cout<<"\t\t\tINPUT MENU\n\n";
	cout<<"Enter the size of array\t";
	cin>>size;
	for (int i=0;i<size;i++)
	{
		cout<<"\nEnter "<<i+1<<"element\t";
		cin>>array[i];
	}
	display();
}
void sort::display()
{
	system("CLS");
	cout<<"\nCurrent array is\n\n";
	for (int i=0;i<size;i++)
	{
		cout<<"\t"<<array[i];
	}
}
int main()
{
	
	sort obj1;
	int choice;
	char continu='y';
	do 
	{
		cout<<"Enter 1 for inputing the numbers\n";
		cout<<"Enter 2 for sorting using Selection Sort\n";
		cout<<"Enter 3 for sorting using Bubble Sort\n";
		cout<<"Enter 4 for sorting using insertion Sort\n";
		cout<<"Enter 5 for display\n";
		cin>>choice;
		switch(choice)
		{
			case 1: obj1.input();
					break;
			case 2: obj1.selectionSort();
					break;
			case 3: obj1.bubbleSort();
					break;
			case 4: obj1.insertionSort();
					break;
			case 5: obj1.display();
					break;
		}
	cout<<"\n\n\t\tDo you want to continue?(y/n)\n";
	cin>>continu;
	}while(continu=='y');
return 0;	
    	
}
