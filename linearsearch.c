#include<stdio.h>
void main()
{
	int n;
	printf("enter the size of array");
	scanf("%d",&n);
	int a[n],i;
	printf("enter %d element in array",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int x,f=0;
	printf("enter the number which you want to search");
	scanf("%d",&x);
	for(i=0;i<n;i++)
	{
		if(a[i]==x)
		{
			f=1;
			break;
		}
		
	}
	if(f==1)
	printf("number is present");
	else
	printf("number is not present");
}
