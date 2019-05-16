#include<stdio.h>
int main()
{
	int n;
	while (scanf("%d", &n) != EOF && n) {
		int bin[1000] = { 0 },count = 0, i = 0;
		while (n) {
			bin[i++] = n % 2;
			n /= 2;
		}
		printf("The parity of ");
		for (int j = i-1; j >= 0; j--) {
			printf("%d", bin[j]);
			if (bin[j] == 1) count++;
		}
		printf(" is %d (mod 2).\n", count);
	}
}