#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *prev,*next;
}*head;
void traverselist();
void creatlist(int n);
void delete_beg();
void delete_last();
void delete(int pos);
void main()
{
	int n,pos;
	printf("enter the value of n:\n");
	scanf("%d",&n);
	creatlist(n);
	printf("list elements:\n");
	traverselist();
	delete_beg();
	printf("final list:\n");
	traverselist();
	delete_last();
	printf("final node:\n");
	traverselist();
	printf("enter position which you want to delete:\n");
	scanf("%d",&pos);
	delete(pos);
	printf("final list:\n");
	traverselist();
}
void creatlist(int n)
{
	struct node *newnode,*temp;
	int data,i;
	head=(struct node*)malloc(sizeof(struct node));
	if(head==NULL)
	{
		printf("unable to creat memory:\n");
		exit(0);
	}
	printf("enter the data of head:\n");
	scanf("%d",&data);
	head->data=data;
	head->next=NULL;
	head->prev=NULL;
	temp=head;
	for(i=2;i<=n;i++)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		if(newnode==NULL)
		{
			printf("unable to creat memory:\n");
			exit(1);
		}
		printf("enter the value of node:\n");
		scanf("%d",&data);
		newnode->data=data;
		newnode->next=NULL;
		newnode->prev=NULL;
		temp->next=newnode;
		newnode->prev=temp;
		temp=temp->next;
	}
}
void traverselist()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("empty list:\n");
		exit(2);	
	}
	temp=head;
	while(temp!=NULL)
	{				
		printf("data=%d\n",temp->data);
		temp=temp->next;
	}
					
}
void delete_beg()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("list empty:\n");
		exit(3);
	}
	temp=head;
	head=head->next;
	temp->next=NULL;
	head->prev=NULL;
	free(temp);
}	
void delete_last()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("list is empty:\n");
		exit(4);
	}
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->prev->next=NULL;
	temp->prev=NULL;
	free(temp);
}
void delete(int pos)
{
	int i;
	struct node *temp;
	temp=head;
	for(i=2;i<=pos;i++)
	{
		if(temp->next==NULL)
		{
			printf("position is not found:\n");
			exit(5);
		}
		if(temp->next!=NULL)
		{
			temp=temp->next;
		}
	}
			temp->prev->next=temp->next;
			temp->next->prev=temp->prev;
			temp->next=NULL;
			temp->prev=NULL;
			free(temp);
}
