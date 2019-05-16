#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
	int a, b;
	while (scanf("%d %d", &a, &b) != EOF && a) {
		int count = 0;
		for (int i = a; i <= b; i++) 
			if (sqrt(i) == (int)sqrt(i)) count++;
		printf("%d\n", count);
	}
}