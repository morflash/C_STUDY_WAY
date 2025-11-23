#include <stdio.h>

int main()
{
	// printf("\a");//让电脑响一下 
	
	/*printf("abcde\\0fg\n");在\0前再加一个\，让\0失去原来的作用 
	printf("abcde\0fg\n");
	*/
	
//	printf("\130");//\ddd（备注：d为一位数字），将ddd这一8进制数转换为10进制 ,再用ASCII转化 
//	printf("\x40");//\xdd（备注：d为一位数字），将dd这一16进制数转换为10进制 ,再用ASCII转化
	
	//大端模式与小端模式：
/*			小端模式（Little-endian）
		低字节存储在低地址，高字节存储在高地址
		类似于我们写数字：个位在前，高位在后
		Intel x86/x64架构采用小端模式
		
			大端模式（Big-endian）
		高字节存储在低地址，低字节存储在高地址
		类似于我们读数字：高位在前，个位在后
		网络字节序、PowerPC、SPARC等采用大端模式
*/

/*
	以32位整数 0x12345678 为例：
	
	小端模式内存布局：
	text
	低地址  -->  高地址
	0x78 0x56 0x34 0x12
	
	大端模式内存布局：
	text
	低地址  -->  高地址
	0x12 0x34 0x56 0x78
*/

	//三目操作符
//	(表达式) ? (表达式) : (表达式)
//		真		结果取这
//		假				  结果取这
//	int a=1,b=2;
//	int c= a>b ? a : b;
//	printf("%d",c); 

	//逗号表达式
//	从左向右依此计算，结果为最后一个逗号后的表达式的结果
//	int a=3,b=5,c=6;
//	c=(b=a+b,b+c,b+a);
//	printf("%d",c);
	
//#define ADD(x,y) ((x)+(y)) //宏定义还可以这么用（定义一个函数？大概这么说） 
//#define MAX(x,y) (x>y ? x:y) 
//	int a=4,b=5;
//	int c=MAX(a,b);
//	printf("%d\n",c);
//	c=ADD(a,b);
//	printf("%d",c);
	
//	int ch;
//	while((ch=getchar())!=EOF){
//		if(ch<'0'||ch>'9')
//			continue;
//		putchar(ch);
//	}//只输出数字，挺有意思，可能有用
//	
	 
//	int a,b,c;
//	scanf("%4d%2d%2d",&a,&b,&c);//%nd;%nf;%nlf;%nc--n为正整数，可控制输入长度 
//	printf("%d %d %d",a,b,c); 
	
//	typedef int INT;//定义重命名，给了这个定义另外一个名字 
//	typedef INT Int; 
//	Int A=1;
//	//经典例子（这里是例子，实际运用的时候要将结构体定义放在外面） 
//	typedef struct teacher{
//		char name[10];
//		char num[15];
//	}TEA;//struct teacher <=> TEA
//	//seruct teacher ta={"Nmm","10086"}; <=> TEA ta={"Nmm","10086"};  
	
	
	return 0;
}
