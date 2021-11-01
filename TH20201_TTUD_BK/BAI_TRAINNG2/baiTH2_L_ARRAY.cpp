#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
	int n,i,num[1100];
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		scanf("%d",&num[i]);
		sort(num,num+n);
		printf("1 ");
		printf("%d\n",num[0]);
		if(num[n-1]>0)
		{
			printf("1 ");
			printf("%d\n",num[n-1]);
			printf("%d",n-2);
			for(i=1;i<n-1;i++)
			printf(" %d",num[i]);
			printf("\n");
		}
		else
		{
			printf("2 ");
			printf("%d %d\n",num[1],num[2]);
			printf("%d",n-3);
			for(i=3;i<n;i++)
			printf(" %d",num[i]);
			printf("\n");
		}
	}
	return 0;
 }
