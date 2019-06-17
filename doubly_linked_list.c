#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *prev,*next;
}*head;
void traverselist();
void creatlist(int n);
void insert_beg(int data);
void insert_last(int data);
void insert(int data,int pos);
void main()
{
	int data,n,pos;
	printf("enter the value of n:\n");
	scanf("%d",&n);
	creatlist(n);
	printf("list is:\n");
	traverselist();
	printf("enter the data which you want to insert in begning:\n");
	scanf("%d",&data);
	insert_beg(data);
	printf("final list is :\n");
	traverselist();
	printf("enter the data which you want to insert at last node");
	scanf("%d",&data);
	insert_last(data);
	traverselist();
	printf("enter the data which you want to insert at last node");
	scanf("%d",&data);
	printf("enter the posation in which you want to insert:\n");
	scanf("%d",&pos);
	insert(data,pos);
	traverselist();
}
void creatlist(int n)
{
	struct node *newnode,*temp;
	int i,data;
	head=(struct node*)malloc(sizeof(struct node));
	if(head==NULL)
	{
		printf("unable to allocate memory:\n");
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
			printf("unable to allocate memory:\n");
			exit(1);
		}
		printf("enter the data of node:\n");
		scanf("%d",&data);
		newnode->data=data;
		newnode->next=NULL;
		newnode->prev=temp;
		temp->next=newnode;
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
void insert_beg(int data)
{
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(head==NULL)
	{
		printf("unable to allocate memory:\n");
		exit(3);
	}
	newnode->data=data;
	newnode->next=NULL;
	newnode->prev=NULL;
	head->prev=newnode;
	newnode->next=head;
	head=newnode;
}
void insert_last(data)
{
	struct node *newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("unable to allocate memory:\n");
		exit(4);
	}
	newnode->data=data;
	newnode->next=NULL;
	newnode->prev=NULL;
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	newnode->prev=temp;
	temp->next=newnode;
	temp=temp->next;
}
void insert(data,pos)
{
	struct node *newnode,*temp;
	int i;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("unable to allocate memory:\n");
		exit(5);
	}
	newnode->data=data;
	newnode->next=NULL;
	newnode->prev=NULL;
	temp=head;
	for(i=2;i<pos;i++)
	{
		if(temp->next==NULL)
		{
			printf("posation not found:\n");
		}
		if(temp->next!=NULL)
		{
			temp=temp->next;
		}
    }
		newnode->next=temp->next;
		newnode->prev=temp;
		temp->next->prev=newnode;
		temp->next=newnode;
	
}
