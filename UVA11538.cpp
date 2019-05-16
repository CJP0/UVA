#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define swap(x,y,t)((t)=(x),(x)=(y),(y)=(t))
int main()
{
	double n, m, temp, count;
	while (scanf("%lf %lf", &n, &m) != EOF && m) {

		if (n > m)
			swap(n, m, temp);
		count = n*m*(m + n - 2) + n*(n - 1)*(3 * m - n - 1) / 3 * 2;
		printf("%lf\n", count);
		n = 0, m = 0;
	}
}