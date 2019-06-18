#include<stdio.h>
void main()
{
	int i,n,first,last,middle,search,t,j;
	printf("enter the size of array");
	scanf("%d",&n);
	int a[n];
	printf("enter the elements of an array");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
    	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("\nsorting elements are %d",a[i]);
	}
	printf("enter the element which you want to search");
	scanf("%d",&search);
	first=0;
	last=n;
	do
	{
		middle=(first+last)/2;
		if(a[middle]<search)
			first=middle+1;
		else if(a[middle]>search)
			last=middle-1;
	}
	while(search!=a[middle] && first<=last);
		
	    if(a[middle]==search)
		{
			printf("search successful");
		}
		else
		{
			printf("search failed");
		}
}
