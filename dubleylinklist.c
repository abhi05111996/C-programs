#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct linklist
{
	struct linklist *prev;
	int data;
	struct linklist  *next;

}linklist;
linklist *createlist()
{
	struct linklist *arr;
	arr=(struct linklist*)malloc(sizeof(struct linklist));
	printf("\nEnter a data");
	scanf("%d",&arr->data);
	arr->next=NULL;
	arr->prev=NULL;
	return arr;
}
linklist *addbeg(struct linklist *arr)
{
	struct linklist *t,*a;
	a=arr;
	t=(linklist*)malloc(sizeof(struct linklist));
	printf("\nEnter a data");
	scanf("%d",&t->data);
	t->next=NULL;
	t->prev=NULL;
	t->prev=a;
	a->next=t;
	arr=t;
	return arr;
}
linklist *addend(struct linklist *arr)
{
	struct linklist *p,*h;
	p=malloc(sizeof(struct linklist));
	printf("\nEnter a data");
	scanf("%d",&p->data);
	p->next=NULL;
	p->prev=NULL;
	h=arr;
	while(h->next!=NULL)
	{
	   h=h->next+1;
	}
	p->prev=h;
	h->next=p;
	return arr;	
}
linklist *addbetween( linklist *arr)
{
	int a;
	linklist *p,*h,*t;
	p=(linklist*)malloc(sizeof(struct linklist));	
	printf("\nEnter a data");
	scanf("%d",&p->data);
	p->next=NULL;
	p->prev=NULL;
	h=arr;
	t=h;
	while(h->next!=NULL)
	{
		h=h->next;
	}
	printf("\nEnter a new data");
	scanf("%d",&a);
    while(t!=h)
    {
    	if(t->data==a)
    	{
    			t->next=p;
            	p->prev=t;
            	p->next=h;
            	h->prev=p;
		}
    	t=t->next;
    	
	}
	return arr;
	
}

void showlist(linklist *arr)
{
	linklist *p;
	p=arr;
	while(p!=NULL);
	{
		printf("\nList value is:%d",p->data);
		p=p->next;
	}
	
}

linklist *clearall(struct linklist *arr)
{
    if(arr->next!=NULL)
    {
      free (arr);
      printf("\nList is deleted");
    }
    else
      printf("\nList already is empty");
    return arr;
}

int main()
{
	linklist *arr;
	arr=createlist();
	int a;
	while(1)
 {
	printf("\n1.Do you want to add begning");
	printf("\n2.Do you want to add end");
	printf("\n3.Do you want to add between");
	printf("\n4.Do you want to show list");
	printf("\n5.Do you want to delete all list");
	printf("\n6.Do you want to exit");
	printf("\n\nEnter your choice");
	scanf("%d",&a);
	switch(a)
	{
		case 1:
			arr=addbeg(arr);
			break;
		case 2:
			arr=addend(arr);
			break;
		case 3:
			arr=addbetween(arr);
			break;
		case 4:
			showlist(arr);
			break;
		case 5:
			clearall(arr);
			break;
		case 6:
			exit(0);
		default:
			printf("\n\n\nInvalid option");
   }
	
 }
 return 0;
}
