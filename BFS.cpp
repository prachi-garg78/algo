#include <iostream>
using namespace std;

struct node 
{
    int info;
    node *next;
};
 
class Queue 
{

        node *front;
        node *rear;
     public:
        Queue();
        void enqueue(int);
         bool isEmpty();
		int dequeue();
        void display();
 
};

Queue::Queue() 
{
    front = NULL;
    rear = NULL;
}

void Queue::enqueue(int data) 
{
    node *temp = new node();
    temp->info = data;
    temp->next = NULL;
    if(front == NULL)
	{
        front = temp;
    }
	else
	{
        rear->next = temp;
    }
    rear = temp;
}
 
int Queue::dequeue() 
{
    node *temp = new node();
    int value;
    if(front == NULL)
	{
        cout<<"\n\n\t\t Queue Underflowed ..... ";
    }
	else
	{
        temp = front;
        value = temp->info;
        front = front->next;
        delete temp;
    }
    return value;
}
void Queue::display()
{
    node *p = new node;
    p = front;
    if(front == NULL)
	{
        cout<<"\n\n\t\t Queue is Underflowed .....";
    }
	else
	{
        while(p!=NULL)
		{
            cout<<p->info<<"   ";
            p = p->next;
        }
    }
}
bool Queue::isEmpty() 
{
    return (front == NULL);
}

class Graph 
{
        int n; // n is the number of vertices in the graph
        int **A; // A stores the edges between two vertices,i.e., The adjacency list of graph ...
    public:
        Graph(int size = 2);
        bool isConnected(int, int);
        void addEdge(int u, int v);
        void BFS(int );
};

Graph::Graph(int size) 
{
    int i, j;
    if (size < 2)
	   n = 2;
    else 
	   n = size;
    A = new int*[n];
    for (i = 0; i < n; i++)
        A[i] = new int[n];
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            A[i][j] = 0;
}

bool Graph::isConnected(int u, int v)
{
    return (A[u-1][v-1] == 1);
}

void Graph::addEdge(int u, int v)
{
    A[u-1][v-1] = 1;
	A[v-1][u-1] = 1;
}

void Graph::BFS(int s)
{
    Queue Q;
         int exp[30];// Keeps track of explored vertices 

         for (int i = 1; i <= n; ++i)  // Initailized all vertices as unexplored 
             exp[i] = 0;
 
    Q.enqueue(s);   // Push initial vertex to the queue 
    exp[s] = 1; // mark it as explored 
	cout << " \n\n\t\t Breadth first Search starting from vertex ...... ";
	
    cout <<s << " : " << endl; 
    cout<<"\n\n\t\t";
	while (!Q.isEmpty()) 
	{
    
        int v = Q.dequeue();    // Pop the vertex from the queue  
        cout << v << "  ";      // display the explored vertices 
        for (int w = 1; w <= n; w++)// Explores the vertex w if it is connected to v and and if it is unexplored 
            if (isConnected(v, w) && exp[w]==0) 
			{
                Q.enqueue(w); // adds the vertex w to the queue 
                exp[w] = 1;  // marks the vertex w as visited 
            }
    }
    cout << endl;
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
	int s;
	cout<<"\n\n\t   Enter the source vertex through which u want to start the bfs ... ";
	cin>>s;
    g.BFS(s);
    cout<<"\n\n\t\t ";
	system("pause");
    return 0;
    
}
