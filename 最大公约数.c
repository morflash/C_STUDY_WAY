#include <stdio.h>
int gys(a,b)
{
	int c;
	while(b!=0)
	{
	c=a%b;
	a=b;
	b=c;
	}
	return a;
}

int main()
{
	int a,b,d;
	scanf("%d %d",&a,&b);
	d=gys(a,b);
	printf("gysΪ%d",d);
	return 0;
}
