#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;
class LinkedListADT
{
	public:
		typedef struct node
		{
			int item;
			node *next;
		}node;
		node* start;
		LinkedListADT()
		{
			start=NULL;
		}
node *search(int data)
{
	node *t;
	if(start==NULL)
		return NULL;
	t=start;
	while(t->next!=NULL)
	{
		if(t->item==data)
		return (t);
		t=t->next;
	}
	return (NULL);
}

	void insertAtstart(int data);
	void insertAtlast(int data);
	void insertAtafter(int curentdata,int data);
   // int search(int data);
	int deletefirst();
    int deletelast();
    int deletecurrentitem(int currentdata);
	int edititem(int currentitem,int newdata);
	int countitem();
	int getfirstitem();
	int getlastitem();
	void viewlist();
	int searchitem(int data);
	void sortlist();
};
void LinkedListADT::sortlist()
{
	node *p,*t;
	int r,i,x,n;
	n=countitem();
	for(r=1;r<=n-1;r++)
	{
		t=start;
		for(i=0;i<=n-1-r;i++)
		{
			if(t->item > t->next->item)
			{
				x=t->item;
				t->item=t->next->item;
				t->next->item=x;
			}
			t=t->next;
		}
	}
}
int LinkedListADT::searchitem(int data)
{
	node *t;
	t=start;
	while(t!=NULL)
	{
		if(t->item==data)
	    	return 1;
		t=t->next;
	}
	return 0;
}
void LinkedListADT::viewlist()
{
	if(start==NULL)
	  cout<<"\nList is empty";
	else
 {
	node *t;
	t=start;
	while(t!=NULL)
	{   cout<<"\n "<<t->item;
		t=t->next;
	}
 }
}
int LinkedListADT::getlastitem()
{
	if(start==NULL)
	{
		cout<<"\nList is empty";
		return -1;
	}
	node *t;
	t=start;
	while(t!=NULL)
	{
		t=t->next;
	}
	return t->item;
}
int LinkedListADT::getfirstitem()
{
	if(start==NULL)
	{
		cout<<"\nList is empty";
		return -1;
	}
	return start->item;
 } 
int LinkedListADT::countitem()
{
	int count=0;
	node *t;
	t=start;
	while(t!=NULL)
	{
		count++;
		t=t->next;
	}
	return count;
}
int LinkedListADT::edititem(int currentitem,int newdata)
{
	node *t=search(currentitem);
	if(t==NULL)
	cout<<"\nItem not found";
	else
	t->item=newdata;
}
int LinkedListADT::deletefirst()
{
	if(start==NULL)
	{
		cout<<"\nUnderflow";
		return 0;
	}
	node *r;
	r=start;
	start=start->next;
	delete r;
	return 1;
}
int LinkedListADT::deletelast()
{
	if(start==NULL)
	{
		cout<<"\nUnderflow";
	}
	if(start->next!=NULL)
	{
		delete(start);
		start=NULL;
		return 1;
	}
	node *t1,*t2;
	t1=t2=start;
	do {
		t2=t1;
		t1=t1->next;
	}
	while(t1->next!=NULL);
	t2->next=NULL;
	delete t1;
	return 1;
}
int LinkedListADT::deletecurrentitem(int currentdata)
{
	node *t=search(currentdata);
	if(t==NULL)
	{
		cout<"\nItem not found";
		return 0;
	}
	while(t->next!=NULL)
	{
		t->item=t->next->item;
		t=t->next;
	}
	deletelast();
	return(0);
	
}

void LinkedListADT::insertAtstart(int data)
{
	node *n=new node;
	n->item=data;
	n->next=start;
	start=n;
}
void LinkedListADT::insertAtlast(int data)
{
	node *n,*t;
	n=new node;
	n->item=data;
	n->next=NULL;
	if(start==NULL)
	start=n;
	else
	{
		t=start;
		while(t->next!=NULL)
		 t=t->next;
		t->next=n;			
	}
	
}
void LinkedListADT::insertAtafter(int currentdata,int data)
{
  node *t=search(currentdata);
  if(t==NULL)
  cout<<"\nNo such value exits";
  else
  {
  	node *n=new node;
  	n->item=data;
  	n->next=t->next;
  	t->next=n;
  }	
}
int main()
{
	LinkedListADT l1;
	int a,b;
	
	l1.insertAtstart(34);
	l1.insertAtlast(56);
	l1.insertAtstart(57);
	a=l1.getfirstitem();
	l1.viewlist();
	l1.countitem();
	cout<<endl<<a;
	getch();
	return 0;
}
