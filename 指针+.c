#include <stdio.h>
int main()
{
	int a[][3]={{1,2,3,},{4,5,6,}} ;
	int b[]={0,3,2,3,4,};
	int *p0=b;
	int (*p)[3]=a;// 指向包含3个int的数组的指针
	printf("%d\n",p0[1]);
	printf("%d\n",*(p0+1));//等同于上一行 
	printf("%d\n",p[1][1]);
	printf("%d\n",*(*(p+1)+1));//等同于上一行 
	
	
	
	return 0;
}
