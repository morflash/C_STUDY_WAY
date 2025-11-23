#include <stdio.h>
#include <string.h>
//struct teacher{
//	char name[10];
//	char num[15];
//};
//int main()
//{
//	struct teacher ta={
//		"Nary","10086"
//	};
//	printf("name=%s,num=%s\n",ta.name,ta.num);
//	
//	struct teacher *pta=&ta;
//	strcpy((*pta).name,"Mary");
//	strcpy((*pta).num,"91100");
////	(*pta).name="Mary";不要再这样了，字符串不能整体赋值 
//	printf("name=%s,num=%s\n",(*pta).name,(*pta).num);
//	printf("name=%s,num=%s\n",pta->name,pta->num);
//	return 0;
//}
//typedef struct student{
//	char name[5];
//	char no[10];
//	int score[3];
//}STU;
//
//void Print(STU *P){
//	printf("name:%s no:%s score:%d,%d,%d\n",P->name,P->no,P->score[0],P->score[1],P->score[2]);
//}; 
//
//int main()
//{
//	STU s[2]={
//		{"Nary","10086",12,13,14},
//		{"Mary","12306",13,14,15},
//	};
//	Print(&s[0]);
//	Print(&s[1]);
//	return 0;
//}
typedef struct student{
	char name[5];
	int no;
	struct student *next;//静态链表的关键 
}STU; 

int main()
{
	STU sa,sb,*head,*p;
	strcpy(sa.name,"Nary");
	sa.no=10086;
	strcpy(sb.name,"Mary");
	sb.no=12306;
	
	head=&sa;//头和尾连接起来 
	sa.next=&sb;
	sb.next=NULL;
	p=head;
	
	do{
		printf("name=%s no:%d\n",p->name,p->no);
		p=p->next;
	}while(p!=NULL);
	
	return 0;
}

