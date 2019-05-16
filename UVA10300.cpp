#include<stdio.h>
int main()
{
	int n, a, b, c;
	scanf("%*d");
	while (scanf("%d", &n) == 1) {
		double sum = 0;
		while (n--) {
			scanf("%d %d %d", &a, &b, &c);
			sum += (double)a*c;
		}
		printf("%.0lf\n", sum);
	}
}