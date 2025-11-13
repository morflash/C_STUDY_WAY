#include <stdio.h>
void g(int *p);
int main()
{
	int a=3;
	g(&a);
	printf("%d\n",a);
	return 0;
}

void g(int *p)
{
	printf("%p\n",p);//这里p就是a的地址了，注意这里是p=&a，加*是为了说明p是一个指针 
	*p=6;//*p相当把a拿起来读或者写了（即访问）
	//所以有了指针就有了子函数改变主函数的值的能力。返回值只能返回一个，索性不返回，直接用指针改变 
}
