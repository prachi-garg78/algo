#include <iostream>
#include <conio.h>

using namespace std;
struct node
{

    int fr, to, cost;

};
int c = 1, temp1 = 0, temp = 0;
int n,m;
void prims1(int a[], int cost[][30] , int i, int j)
{

    a[i] = 1;
    node p[n];
    while (c <=n)
    {

        int min = 999;

        for (int i = 1;i<=n; i++)

        {
           if (a[i] == 1)

            {

                for (int j = 1; j<=n; )

                {

                    if (cost[i][j] >= min || cost[i][j] == 0)

                    {

                        j++;

                    }

                    else if (cost[i][j] < min)

                    {

                        min = cost[i][j];

                        temp = i;

                        temp1 = j;

                    }

                }

            }

        }

        a[temp1] = 1;

        p[c].fr = temp;

        p[c].to = temp1;

        p[c].cost = min;

        c++;       

        cost[temp][temp1] = cost[temp1][temp]=1000;

    }

    for (int k = 1; k<n; k++)

    {

        cout<<"\n\n\t\t source node      :-  "<<p[k].fr;

        cout<<"\n\t\t destination node :-  "<<p[k].to;

        cout<<"\n\t\t weight of node   :-  "<<p[k].cost;

    }

}



int main()
{
    int k;
    cout<<"\n\n\t\t Enter no. of vertices .... ";
    cin>>n;
	cout<<"\n\n\t\t Enter no. of edges .... ";
	cin>>m;
    int a[n];
    for (int i = 1; i <=m; i++)
	{
      a[i] = 0;
    }

    int cost[30][30];
    int i,j,c1;
    cout<<"\n\n\t\t Enter Cost of every Edge .... ";
	for(k=1;k<=m;k++)
	{
		cout<<"\n\n\t\t Enter the source vertex .... ";
		cin>>i;
		cout<<"\n\n\t\t Enter the destination vertex .... ";
		cin>>j;
		cout<<"\n\n\t\t Enter the cost of this edge .... ";
		cin>>c1;
		cost[i][j]=c1;
		cost[j][i]=c1;
	}

    prims1(a,cost,1,1);
	getch();
}

