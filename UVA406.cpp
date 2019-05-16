#include <stdio.h>
#include <stdlib.h>
int determin(int);
int main()
{
	int in,c;
	while (scanf("%d %d", &in, &c) != EOF) {
		int prime[200],p=0;
		printf("%d %d:", in, c);
		for (int i = 1; i <= in; i++) {
			if (determin(i)) {
				prime[p] = i;
				p++;
			}
		}
		int strp = (p % 2) ? (p / 2) - c + 1 : p / 2 - c;
		int stop = (p % 2) ? strp + (c * 2) - 1 : strp + (c * 2);
		if(strp < 0)
			strp = 0;
		if(stop > p)
			stop = p;
		for (int i = strp; i < stop; i++)
			printf(" %d", prime[i]);
		printf("\n\n");
	}
}
int determin(int t) {
	for (int i = 2; i < t; i++) {
		if ((t%i) == 0) {
			return 0;
			break;
		}
	}
	return 1;
}