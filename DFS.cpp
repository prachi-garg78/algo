using namespace std;
#include<iostream>

struct node
{
    int info;
    node *next;
};

class stack
{
        node *top;
     public:
        stack();
        void push(int);
        int pop();
        bool isEmpty();
        void display();
}; 
 
stack::stack()
{
    top = NULL;
} 
 
void stack::push(int data)
{
    node *p;
    p = new node;
    p->info = data;
    p->next = NULL;
    if(top!=NULL){
        p->next = top;
    }
    top = p;
} 
 
int stack::pop()
{
    node *temp;
    int value;
    if(top==NULL)
	{
        cout<<"\n\n\t\t The stack is Underflowed ..... ";
    }
	else
	{
        temp = top;
        top = top->next;
        value = temp->info;
        delete temp;
    }
    return value;
} 
 
bool stack::isEmpty()
{
    return (top == NULL);
} 
 
void stack::display()
{
    node *p = top;
    if(top==NULL)
	{
        cout<<"\n\n\t\t Stack Is Empty .... ";
    }
	else
	{
        cout<<"\n\n\t\t The Stack Is As Follows .... ";
        while(p!=NULL)
		{
            cout<<p->info<<endl;
            p = p->next;
        }
    }
} 

class Graph 
{
        int n;
        int **A;
     public:
        Graph(int size = 2);
        bool isConnected(int, int);
        void addEdge(int x, int y);
        void DFS(int);
}; 
 
Graph::Graph(int size) 
{
    int i, j;
    if (size < 2) n = 2;
    else n = size;
    A = new int*[n];
    for (i = 0; i < n; ++i)
        A[i] = new int[n];
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; ++j)
            A[i][j] = 0;
} 

bool Graph::isConnected(int x, int y)
{
    return (A[x-1][y-1] == 1);
} 
 
void Graph::addEdge(int x, int y) 
{
    A[x-1][y-1] = A[y-1][x-1] = 1;
} 
 
void Graph::DFS(int x)
{
    stack s;
    bool *visited = new bool[n+1];
    int i;
    for(i = 0; i <= n; i++)
        visited[i] = false;
    s.push(x);
    visited[x] = true;
    cout << "\n\n\t\t Depth first Search starting from vertex ... ";
    cout << x << " : " ;
    cout<<"\n\n\t\t  ";
    while(!s.isEmpty())
	{
        int k = s.pop();
        cout<<k<<"   ";
        for (i = n; i >= 0 ; --i)
            if (isConnected(k, i) && !visited[i]) 
			{
                s.push(i);
                visited[i] = true;
            }
    }
    cout<<endl;
    delete [] visited;
} 
int main()
{
    int n,x1,x2;
    char ans;
	cout<<"\n\n\t\t Enter the total no of vertices u want in the graph  ..... ";
	cin>>n; 
    Graph g(n);  // Creates a graph with n vertices 
    cout<<"\n\n\t\t Enter the Adjacency list of the graph ..... ";
    do
    {
    		cout<<"\n\n\t\t Enter the source vertex :- ";
    		cin>>x1;
    		cout<<"\n\n\t\t Enter the destination vertex  :-  ";
    		cin>>x2;
    		g.addEdge(x1,x2);
		    cout<<"\n\n\t\t Do U want to add no. of edges .... ";
		    cin>>ans;
	}while(ans=='Y'||ans=='y');

    g.DFS(1);
    cout<<"\n\n\t\t  ";
    system("pause");
    return 0;
}
