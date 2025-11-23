#include <stdio.h>
int cou(int year,int m)//将几月份有多少天算出
{
	if(m==1||m==3||m==5||m==7||m==8||m==10||m==12) m=31;
	else if(m==4||m==6||m==9||m==11) m=30;
	else
	{
		if((year%4==0 && year%100!=0)||year%400==0) m=29;
		else m=28;
	}
	return m;
}

int year_1(int year,int *mouth)//返回某年某月一号对应星期几；将输入的月份转化为当月的天数 
{	
	int mouth0=*mouth; 
	*mouth=cou(year,*mouth);
	
	int n=1;
	int year0=1900;//初始数据来自1900年1月一号对应星期一 
	for(year0=1900;year0<year;year0++)
	{ 
		if((year0%4==0 && year0%100!=0)||year0%400==0) n+=2;
		else n+=1;
	}
	if(n>7) n=n%7; 
	if(n==0) n=7;//每年的一月一号对应的星期几
	
	if(mouth0!=1)
	{
		int i;
		int sum=0;
		for(i=1;i<mouth0;i++)
		{
			sum+=cou(year,i);
		}
		n=(sum-(8-n))%7+1;
		if(n>7) n=n%7;
	} 
	return n;//某月一号对应星期几
}

int main()
{
	int year;
	int mouth;
	int year_;
	int a;
	while(1)
	{
	printf("请输入想要的操作，[1]查询日历，[0]退出\n");
	scanf("%d",&a);
	if(a){
		printf("请输入你需要查询的日期，输入格式:如需要查询2023年11月，请输入2023 11\n");
		scanf("%d %d",&year,&mouth);
	year_=year_1(year,&mouth);//等待增加内容 
//	printf("%d %d\n",year_,mouth);
	printf("一\t二\t三\t四\t五\t六\t日\t\n");
//	printf("8-year_=%d\n",8-year_);
	switch (year_-1){
	case 0:
		break;
	case 1:
		printf("\t");
		break;
	case 2:
		printf("\t\t");
		break;
	case 3:
		printf("\t\t\t");
		break;
	case 4:                
	    printf("\t\t\t\t");
		break;
	case 5:                
	    printf("\t\t\t\t\t");
		break;
	case 6:                
	    printf("\t\t\t\t\t\t");
		break;
	default:
		printf("什么东西");
		}
	int i;
	int j=1;
	
	for(i=1;i<=mouth/*根据月份修改*/;i++)
	{	
		printf("%d\t",i);
		if(8-year_-j==0)
		{
			year_=1;
			j=0;
			printf("\n");
		}
		j++; 
	 }
	printf("\n");
	}
	else break;
	}
	return 0;
}
