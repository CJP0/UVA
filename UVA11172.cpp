#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a, b;
	scanf("%*d");
	while(scanf("%d %d", &a, &b) != EOF) {
		if (a > b)printf(">\n");
		else if (a < b)printf("<\n");
		else printf("=\n");
	}
}