#include <stdio.h>
#include <stdlib.h>

typedef struct node
{ int data; struct node* next; }node;
typedef struct list
{ node *head,*tail; }list;

void ins_beg(list* l,int k)
{
	node* temp=(node*)malloc(sizeof(node));
	temp->data=k; temp->next=l->head;
	if(l->tail==NULL) l->tail=temp;
	l->head=temp;
}

void ins_end(list* l,int k)
{
	node* temp=(node*)malloc(sizeof(node));
	temp->data=k; temp->next=NULL;
	if(l->head==NULL) l->head=temp;
	else l->tail->next=temp;
	l->tail=temp;
}

void print(list l)
{	
	while(l.head!=NULL)
	{
		printf("%d ",l.head->data);
		l.head=l.head->next;
	}
	printf("\n");
}

node* merge(node *h1,node *h2) 
{
	node *new_head;
	if(h1==NULL) return h2;
	if(h2==NULL) return h1;
	
	if(h1->data<h2->data) 
	{
  		new_head=h1;
  		new_head->next=merge(h1->next,h2);
	} 
	else 
	{
  		new_head=h2;
  		new_head->next=merge(h1,h2->next);
 	}
 	return new_head;
}

node* msort(node *head)
{
	node *mid,*temp;

 	if(head==NULL||head->next==NULL) 
  		return head;

	mid=head; temp=head->next;
	while(temp!=NULL && temp->next!=NULL) 
	{
		mid=mid->next;
	 	temp=temp->next->next;
	}

	temp=mid->next;
	mid->next = NULL;
	return merge(msort(head),msort(temp));
}

int main()
{
	list l1;
	l1.head=NULL;
	l1.tail=NULL;

	ins_end(&l1,23);
	ins_beg(&l1,4);
	ins_end(&l1,53);
	
	ins_end(&l1,3);
	ins_beg(&l1,86);
	ins_end(&l1,2);

	ins_end(&l1,-2);
	ins_beg(&l1,48);
	ins_end(&l1,51);

	ins_end(&l1,278);
	ins_beg(&l1,-46);
	ins_end(&l1,0);

	print(l1);
	l1.head=msort(l1.head);
	print(l1);
}