#include<iostream>
#include<cstdlib>
using namespace std;

struct node 
{
	int data;
	char color;
	node *left;
	node *right;
	node *p;
};
node *nil;
class tree
{
    node *root , *temp;
 public:
	void rbinsert(int );
	void search(int x);
	node* createnode(int );
	void inorder(node* );
	node* retroot();
	void leftrotate(node*);
	void rightrotate(node* );
	void rbfixup(node*);
	void deletefixup(node*);
	void rbdelete();
	char retcolor(node* );
	node* successor(node* );
	void deletet(node*);
	void deletebycopy(node*);
	tree();
};
tree::tree() 
{
	root = temp = nil;
}

node* tree::createnode (int e)
{
	temp= new node;
	temp->data=e;
	temp->left=nil;
	temp->right=nil;
	temp->color='R';
}
//---------------------------------rb----------insert---------------------
void tree::rbinsert(int e)
{
	temp=createnode(e);
	if(root == nil)
	{
		root=temp;
		root->p=nil;
	}
	else
	{
		node *y=root,*prev;
		while(y!=nil)
		{
			prev=y;
			if(e > y->data)
			{	
				y=y->right;
				continue;
			}
			if(e <= y->data)
			{	
				
				y=y->left;
				continue;
			}
		}
		if(e <= prev->data)
		{
			prev->left=temp;
			temp->p=prev;
		}
		else
		{
			prev->right=temp;
			temp->p=prev;
		}
	}
	rbfixup(temp);
}
void tree::search(int x)
{
     if(root==NULL)
     {
           cout<<"\n\n\t\t  Empty Tree ...... " ;
           return  ;
     }
     
     node *p=root;
     int found=0;
     while(p!=NULL&& found==0)
     {
            if(p->data==x)
                found=1;
            if(found==0)
            {
                 if(p->data<x)
                      p=p->right;
                 else
                      p=p->left;
            }
     }
     if(found==0)
          cout<<"\n\n\t\t Element Not Found.";
     else
     if(found==1)
     {
        cout<<"\n\t\t Key   :- "<<p->data;
        cout<<"\n\t\tColor  :- "<<p->color;
        
     }
}

char tree::retcolor(node *x)
{
	if(x==nil)
	return 'B';
	return x->color;
}
//--------------------------------------LEFT--------rotate----------
void tree::leftrotate(  node* x ) 
{
    node* y;
    y = x->right;
    /* Turn y's left sub-tree into x's right sub-tree */
    x->right = y->left;
    if ( y->left != nil )
        y->left->p = x;
    /* y's new p was x's p */
    y->p = x->p;
    /* Set the p to point to y instead of x */
    /* First see whether we're at the root */
    if ( x->p == nil ) root = y;
    else
        if ( x == (x->p)->left )
            /* x was on the left of its p */
            x->p->left = y;
        else
            /* x must have been on the right */
            x->p->right = y;
    /* Finally, put x on y's left */
    y->left = x;
    x->p = y;
    }
//--------------------------------RIGHT---------rotate-----------------------
void tree::rightrotate(  node* x )
{
    node* y;
    y = x->left;
    /* Turn y's left sub-tree into x's right sub-tree */
    x->left = y->right;
    if ( y->right != nil )
        y->right->p = x;
    /* y's new p was x's p */
    y->p = x->p;
    /* Set the p to point to y instead of x */
    /* First see whether we're at the root */
    if ( x->p == nil ) root = y;
    else
        if ( x == (x->p)->left )
            /* x was on the left of its p */
            x->p->left = y;
        else
            /* x must have been on the right */
            x->p->right = y;
    /* Finally, put x on y's left */
    y->right = x;
    x->p = y;
}    
    
    
node* tree::retroot()
{
	return root;
}
//-------------------------------rb insert fixup---------------------------
void tree::rbfixup(node* x)
{
    while ( (x != root) && (retcolor(x->p) == 'R') ) {
       if ( x->p == x->p->p->left ) {
           /* If x's p is a left, y is x's right 'uncle' */
           node * y = x->p->p->right;
           if ( retcolor(y) == 'R' ) {
               /* case 1 - change the colours */
               x->p->color = 'B';
               y->color = 'B';
               x->p->p->color = 'R';
               /* Move x up the tree */
               x = x->p->p;
               }
           else {
               /* y is a 'B' node */
               if ( x == x->p->right ) {
                   /* and x is to the right */ 
                   /* case 2 - move x up and rotate */
                   x = x->p;
                   leftrotate(  x );
                   }
               /* case 3 */
               x->p->color = 'B';
               x->p->p->color = 'R';
               rightrotate( x->p->p );
               }
           }
       else {
           node * y = x->p->p->left;
           if ( retcolor(y) == 'R' ) {
               /* case 1 - change the colours */
               x->p->color = 'B';
               y->color = 'B';
               x->p->p->color = 'R';
               /* Move x up the tree */
               x = x->p->p;
               }
           else {
               /* y is a 'B' node */
               if ( x == x->p->left ) {
                   /* and x is to the right */ 
                   /* case 2 - move x up and rotate */
                   x = x->p;
                   rightrotate(  x );
                   }
               /* case 3 */
               x->p->color = 'B';
               x->p->p->color = 'R';
               leftrotate( x->p->p );
               }       
              
           }
       }
       
    /* color the root 'B' */
    root->color = 'B';
    }
//-------------------------------------------rb-------delete---------------------------
void tree::rbdelete()
{
	int e;
	cout<<"Enter value to be deleted\n";
	cin>>e;
	node *t=retroot();
	if(t==nil)
	{
		cout<<"Tree is Empty\n";
		return;
	}
	while(t !=nil)
	{	
		if(t->data == e)
		 break;
		if(t->data < e)
		 t=t->right;
		else
		 t=t->left;
	}
	if(t==nil)
	{
		cout<<"Entered no. is not in tree\n";
		return;
	}
	if(t->left==nil || t->right==nil)
	{
		deletet(t);
		return;
	}
	else
	{
		deletebycopy(t);
		return;
	}
}	
//--------------deletet---for--normal--delete-------------------------
void tree:: deletet(node* t)
{
node *x;
if(t==root)
{
	if(t->left==nil && t->right==nil)
	{
		root=nil;
	}
	if(t->left==nil)
	{
		root=t->right;
		root->p=nil;
		x=t->right;
	}
	if(t->right == nil )
	{
		root=t->left;
		root->p=nil;
		x=t->left;
	}
}
else
{	
if(t->left == nil )
	{
		if(t==t->p->left)
			{
				cout<<t->p->data<<endl;	
				t->p->left=t->right;
				   t->right->p=t->p;
				x=t->right;
				
			}
		else
			{
				
				t->p->right=t->right;
				t->right->p=t->p;
				x=t->right;
			}
	}
else{
	if(t->right==nil)
	{
		if(t==t->p->left)
			{
				t->p->left=t->left;
				t->left->p=t->p;
				x=t->left;	
			}
		else
			{
				t->p->right=t->left;
				t->left->p=t->p;
				x=t->left;
			}
	}
    }
}
		char c=t->color;
		delete t;
		if(c=='B')
			deletefixup(x);
		return;

}
//-----------------------------------deletebycopy---------------------
void tree::deletebycopy(node* t)
{
	node* y=successor(t);
	t->data=y->data;
	deletet(y);	
}
//--------------------------successor-----------------------------------------
node* tree::successor(node *x)
{
if(x->right!=nil)
	{
		x=x->right;
		while(x->left!=nil)
		x=x->left;
	}
return x;
}
//----------------delete---------------fixup----------------------------------
void tree::deletefixup(node* x)
{

	node *w;
	while (x!=root && retcolor(x) == 'B')
	{
		if(x==x->p->left)
		{
			w=x->p->right;
			if(retcolor(w)=='R')
			{
				w->color='B';
				x->p->color='R';
				leftrotate(x->p);
				w=x->p->right;
			}
			if(retcolor(w->left)=='B' && retcolor(w->right)=='B')
			{
				w->color='R';
				x=x->p;
			}
			else
			{
				if(retcolor(w->right)=='B')
				{
					w->left->color='B';
					w->color='R';
					rightrotate(w);
					w=w->right;
				}
				w->color=x->p->color;
				x->p->color='B';
				w->right->color='B';
				leftrotate(x->p);
				x=root;
			}
		}
		else
		{
			w=x->p->left;
			if(retcolor(w)=='R')
			{
				w->color='B';
				x->p->color='R';
				rightrotate(x->p);
				w=x->p->left;
			}
			if(retcolor(w->left)=='B' && retcolor(w->right)=='B')
			{
				w->color='R';
				x=x->p;
			}
			else
			{
				if(retcolor(w->left)=='B')
				{
					w->right->color='B';
					w->color='R';
					leftrotate(w);
					w=w->left;
				}
				w->color=x->p->color;
				x->p->color='B';
				w->left->color='B';
				rightrotate(x->p);
				x=root;
			}
		}
	}
	if(x!=nil)
	x->color='B';
}


//---------------------------------inorder-------------------
void tree::inorder(node* x)
{

if(x!=nil)
{
	inorder(x->left);
	if(x==root)
	{
	 cout<<" root "<<x->data<<" "<<x->color<<"\n";
	 }else
		{ 
		cout<<x->data<<" "<<x->color<<" |";
		}
	inorder(x->right);
}
}

int main()
{
	nil=new node;
	nil->left=nil->right=NULL;
	nil->color='B';
	nil->p=NULL;
	tree t;
	int x;
	while(1)
	{
	cout<<"\nMenu\n";
	cout<<"1.Insertion\n";
	cout<<"2.Deletion\n";
	cout<<"3.Search\n";
	cout<<"4.Exit\n";
	cin>>x;
	switch(x)
	{
		case 1:cout<<"Enter value to be inserted\n";
		       cin>>x;
		       t.rbinsert(x);
		       cout<<"tree:-\n";
		       t.inorder(t.retroot());
		       break;
	    case 2:t.rbdelete();
		       cout<<"tree:-\n";
		       t.inorder(t.retroot());
		       break;
		case 3:int x;
               cout<<"\n\n\t\t Enter key of the node to be searched .....  ";
               cin>>x;
		       t.search(x);
		       break;       
		case 4:exit(0);
	}
	}
	return 0;
}

	
			
			
		


