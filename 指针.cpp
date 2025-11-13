#include <stdio.h>
int main()
{
	int a[]={1,2,3,4,5,6,};
	int *p=a;
	printf("%d\n",*p);
	printf("%d\n",p[0]);
	//指针的加减 
	printf("%d\n",*p++);
	printf("%d\n",*p);
	printf("%d\n",p[0]);//p+1之后，p[0]就是2，p加上下标就是从p开始数 
	printf("\n");
	
	//指针的相赋,如果指针类型不同，不能相赋
	int c[]={1,2,3,4,5,6,};
	int b[]={7,8,9,10,};
	int *p0=c;
	int *p1=b;
	printf("%d,%d\n",p0[0],p1[0]);
	p1=p0;//赋过去之后，就是p1和p0都指向了c[] 
	printf("%d\n",p0[3]);
	printf("%d\n",p1[3]);
	
	
	return 0;
}
