#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int GCD(int a, int b) {
	if (b) while ((a %= b) && (b %= a));
	return a + b;
}
int main()
{
	int G, i, j, N;
	while (scanf("%d", &N) != EOF && N) {
		G = 0;
		for (i = 1; i<N; i++)
			for (j = i + 1; j <= N; j++)
				G += GCD(i, j);
		printf("%d\n", G);
	}
}