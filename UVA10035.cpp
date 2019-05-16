#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	long long a, b;
	int carry;
	while (scanf("%lld %lld", &a, &b) != EOF) {
		if ((a + b) == 0) break;
		int count = 0;
		carry = 0;
		while (a || b) {
			carry = (((a % 10) + (b % 10))+carry) / 10;
			if (carry) count++;
			if (a) a /= 10;
			if (b) b /= 10;
		}
		if (count) printf("%d ", count);
		else printf("No ");
		printf("carry operation");
		if (count > 1) printf("s.\n");
		else printf(".\n");
	}
}