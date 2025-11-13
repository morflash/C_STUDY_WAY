#include <stdio.h>

void aaa(int *b)
{
	printf("%d\n",b[0]);
	printf("%p\n",b);
	b[0]=100;
	printf("aaa sizeof(b)= %d\n",sizeof(b));
}//数组不需要通过*去交互，只要传入子函数里的是一个数组的地址，就可以直接读写那个数组

void ccc(int *p)
{
	printf("ccc *p=%p\n",p);
	*p=14;
}//普通变量就需要用*去交互

int main()
{
	int a[]={1,2,3,4,5,};
	int *p=a;
	printf("%p\n",a);
	printf("%p\n",p);
	aaa(a);
	printf("%d\n",a[0]);
	printf("main sizeof(a)= %d\n",sizeof(a));

	int c=12;
	ccc(&c);
	printf("main *p=%p\n",&c);
	printf("%d\n",c);
	
	int e[]={1,2,3,4,5,};
	int *d=e;
	printf("%d ",d[1]);
	printf("%d\n",*(d+1));//指针+1意思是跳到了下一个存储单元，即由&e[0]跳到&e[1]
	int *p0=&e[0];
	int *p1=&e[4];
	printf("%d\n",p1-p0);//p1-p0的结果是整数，表示e[0]到e[4]之间元素的个数，可以看作左闭右开
	
	
	
	return 0;
}
