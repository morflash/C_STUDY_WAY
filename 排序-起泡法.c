#include <stdio.h>
int main()
{
	//ÆðÅÝ 
	int a[10]={1,3,5,7,2,4,6,8,10,9};
	int j,i,t;
	
	for(i=0;i<9;i++)
	{
		for(j=0;j<9-i;j++)
		{
			if(a[j]>a[j+1])
			{
			t=a[j];
			a[j]=a[j+1];a[j+1]=t;
			}
		}
	}
	
	for(i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
	
	return 0;
}
