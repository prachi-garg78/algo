using namespace std;
#include<iostream>
#include<fstream>
int k=0;
void quicksort(int a[],int first,int last)
{
     int lower=first+1;
     int upper=last;
     int pivot=a[first];
     while(lower<=upper)
     {
        while(pivot>a[lower])
        {
		lower++;
        k++;
        }
		while(pivot<a[upper])
        {
		 upper--;
         k++;
        } 
		if(lower<upper)
         swap(a[lower++],a[upper--]);
        else
        lower++;
     }
     swap(a[upper],a[first]);
     if(first<upper-1)
     quicksort(a,first,upper-1);
     if(upper+1<last)
     quicksort(a,upper+1,last);
}
int main()
{
	ifstream f;
	f.open("average.txt");
	int i=0;
	int a[200];
	while(!f.eof())
	{
		f>>a[i];
		i++;
	}
    int count=i-1;
	cout<<"\n\n\t\t The array is as follows :- ";
	for(i=0;i<count;i++)
	cout<<a[i]<<"  ";
    quicksort(a,0,count-1);
    cout<<"\n\n\t\t The sorted array is as follows :- ";
	for(i=0;i<count;i++)
	cout<<a[i]<<"  ";
	cout<<"\n\n\t\t The total no of comparisons are :-  "<<k;
    ofstream f1;
    f1.open("averagequick.txt");
    char x=' ';
    for(i=0;i<count;i++)
    {
    	f1<<a[i];
    	f1<<x;
    }
    f.close();
    f1.close();
    cout<<"\n\n\t\t ";
    system("pause");
    return 0;
}
