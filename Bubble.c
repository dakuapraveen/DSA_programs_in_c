#include<stdio.h>
#include<conio.h>
void main()
{
	int n,i,j,t,c=0;
	printf("enter the size of array");
	scanf("%d",&n);
	int a[n];
	printf("enter elements in array");
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
				c++;
			}
		}
	}
	printf("total=%d",c);
	for(i=0;i<n;i++)
	{
		printf("\nsorting elements are %d",a[i]);
	}
}
