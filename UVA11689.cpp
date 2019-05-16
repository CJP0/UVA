#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int n, e, f, c;
	while (scanf("%d", &n) != EOF) {
		while (n--) {
			scanf("%d %d %d", &e, &f, &c);
			e += f;
			int count = 0;
			while (e >= c) {
				count += e / c;
				e = (e / c) + (e%c);
			}
			printf("%d\n", count);
		}
	}
}