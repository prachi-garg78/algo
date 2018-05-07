#include"iostream"
#include"stdio.h"
#include"conio.h"
using namespace std;
class adjacencyList 
{
	int data;
	adjacencyList* next;
	adjacencyList()
	{
	 	
		
	}
	friend class graphs;
}
class graphs
{
	int matrix[10][10];
	int vertices;
public:	void input();
	void display();
};
void graphs::input()
{
	cout<<"Enter the number of vertices";
	cin>>vertices;
	cout<<"Enter the edge data";
	char choice='n';
	for (int i=0;i<vertices;i++)
	{
	 for (int j=0;j<vertices;j++)
	 {
	 	if(i==j)
	 	{
	 		continue;
		 }
	 	cout<<"Is there an edge between"<<i<<"And"<<j<<"?\n";
	 	cin>>choice;
	    if (choice=='y')
	 	{
	 		if (matrix[i]->next==NULL)
	 		matrix[i]->next=new adjacencyList(1,NULL);
		 }
		 else
		 {
		 	matrix[i][j]=0;
		 }	
	 }
	}
}
void graphs::display()
{
	cout<<"The adjacency matrix for graphs is:\n";
	for(int i=0;i<vertices;i++)
	{
		cout<<"\n";
		for (int j=0;j<vertices;j++)
		{
			cout<<matrix[i][j]<<"\t";
		}
	}
}
int main()
{
	graphs obj;
	obj.input();
	obj.display();
	return 0;
}
