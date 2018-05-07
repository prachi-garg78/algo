using namespace std;
#include<iostream>
#include<fstream>
int k=0;
void insertion(int a[],int n)
{
	 for(int i=1;i<n;i++)
    {
           int temp=a[i];
            int j=i-1;
            while(a[j]>temp && j>=0)
            {
                  a[j+1]=a[j];
                  j--;
                  k++;
            }
            a[j+1]=temp;
    }

}
int main()
{
	ifstream f;
	f.open("worse.txt");
	int i=0;
	int a[200],count=0;
	while(!f.eof())
	{
		f>>a[i];
		i++;
	}
	count=i-1;
	cout<<"\n\n\t\t The array is as follows :- ";
	for(i=0;i<count;i++)
	cout<<a[i]<<"  ";
	insertion(a,count);
	cout<<"\n\n\t\t The sorted array is as follows :- ";
	for(i=0;i<count;i++)
	cout<<a[i]<<"  ";
    ofstream f1;
    f1.open("worsewrite.txt");
    char x=' ';
    for(i=0;i<count;i++)
    {
    	f1<<a[i];
    	f1<<x;
    }
    cout<<"\n\n\t\t The total no of comparisons are :-  "<<k;
    f.close();
    f1.close();
    cout<<"\n\n\t\t ";
    system("pause");
    return 0;
}
