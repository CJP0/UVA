#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a,b;
	while(scanf("%d %d",&a,&b) != EOF)
	{
		int m=a; 
		while(a>=b)
		{
			m+=a/b;
			a=a/b+a%b;
		}
	printf("%d\n",m);
	}
 } 
