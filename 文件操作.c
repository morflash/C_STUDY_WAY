#include <stdio.h>
#include <string.h>
#include <errno.h>
struct A{
	char name[10];
	int num;
};
int main()//二进制读写文件 
{
//		FILE*pf=fopen("C:\\Users\\norflash\\Desktop\\test.txt","wb");
//		if(pf==NULL)
//		{
//			perror("fopen");
//			return 1;
//		}
//		
//		struct A a={"Tom",12345
//		};
//	//	fwrite("123",sizeof("123"),1,pf);
//		fwrite(&a,sizeof(struct A),1,pf);
//		
//		fclose(pf);
//		pf=NULL;
	
	FILE*pf1=fopen("C:\\Users\\norflash\\Desktop\\test.txt","rb");
	if(pf1==NULL)
	{
		perror("fopen");
		return 1;
	}
	struct A b={0
	};
	fread(&b,sizeof(struct A),1,pf1);
	printf("%s %d",b.name,b.num);
	fclose(pf1);
	pf1=NULL;
	return 0;
} 

//int main()
//{
//	//打开文件 
//	FILE*pf=fopen("C:\\Users\\norflash\\Desktop\\test.txt","w");//前面是路径，后面是模式 
//																//w是写进文件，r是从文件读出，a是追加，
//																//wb是写二进制进文件，rb是读二进制出文件
//	//判断是否正确打开 
//	if(pf==	NULL)
//	{
//		//printf("%s\n",strerror(errno));
//		perror("fopen");
//		return 1;
//	}
//	
//	char c='a';
//	fputc(c,pf);
//	fputc('\n',pf);
//	fputc('a',pf);
//	fputc('\n',pf);
//	
//	char a[10]="qwerqwe";
//	fputs("hello,toto\n",pf);
//	fputs(a,pf);
//	
//	fprintf(pf,"ehehheeheh\n");
//	fprintf(pf,"%c%s",c,a);
//	
//	//关闭文件
//	fclose(pf);
//	pf=NULL;
//	/////////////////////////////////////////////////////
//	FILE*pf1=fopen("C:\\Users\\norflash\\Desktop\\test.txt","r");
//	if(pf1==NULL)
//	{
//		perror("fopen");
//	}
//	
//	char b;
//	b=fgetc(pf1);
//	printf("%c",b);
//	b=fgetc(pf1);
//	printf("%c",b);
//	b=fgetc(pf1);
//	printf("%c",b);
//	b=fgetc(pf1);
//	printf("%c",b);
//	
//	char d[15];
//	fscanf(pf1,"%s",d);
//	printf("%s",d);
//	
//	fclose(pf1);
//	pf1=NULL;
//	
//	return 0;
//}
