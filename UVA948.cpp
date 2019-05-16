#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	int fibs[45];
	fibs[0] = 1;
	fibs[1] = 1;
	for (int i = 2; i < 45; i++)
		fibs[i] = fibs[i - 1] + fibs[i - 2];
	int s,in;
	scanf("%d", &s);
	while (s--) {
		int p=0;
		scanf("%d", &in);
		printf("%d = ", in);
		for (int i = 44; i > 0;i--) {
			if (in >= fibs[i] && p==0)
				p = 1;
			if (p) {
				if (in >= fibs[i]) {
					printf("1");
					in -= fibs[i];
				}
				else
					printf("0");
			}
		}
		printf(" (fib)\n");
	}
}
