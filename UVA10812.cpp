#include<stdio.h>
int main()
{
	int s, f, n;
	scanf("%*d");
	while (scanf("%d %d", &s, &f) != EOF) {
		if ((s + f) % 2 || f > s) { printf("impossible\n"); continue; }
		int temp = (s + f) / 2;
		printf("%d %d\n", temp, s - temp);
	}
}