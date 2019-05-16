#include<stdio.h>
int main()
{
	scanf("%*d");
	int a, b, n=0;
	while (scanf("%d", &a) != EOF) {
		scanf("%d", &b);
		int sum = 0;
		for (int i = a % 2 ? a : a + 1; i <= b; i += 2) sum += i;
		printf("Case %d: %d", ++n, sum);
	}
}