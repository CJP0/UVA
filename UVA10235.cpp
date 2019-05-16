#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int det(int in) {
	for (int i = 2; i<in; i++)
		if ((in%i) == 0) return 0;
	return 1;
}
int main()
{
	int n;
	while (scanf("%d", &n) != EOF) {
		int n2 = 0, n3 = n;
		if (det(n) == 0) {
			printf("%d is not prime.\n", n);
			continue;
		}
		while (n) {
			n2 = (n2 * 10) + (n % 10);
			n /= 10;
		}
		if (n3 != n2 && det(n2)) printf("%d is emirp.\n", n3);
		else printf("%d is prime.\n", n3);
	}
}