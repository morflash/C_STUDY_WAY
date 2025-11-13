#include <stdio.h>
int main()
{
	int time;
	scanf("%d",&time);
	
	int t=time/100;
	double k=time/100.0;
	int z=(k-t)*100;
	printf("%d %d",t,z);
	
	return 0;
}
