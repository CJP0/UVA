#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int n;
	while (scanf("%d", &n) != EOF) {
		int a = 1, b = 1,f,x=n-1;
		while (x--) {
			if (a == 1 && b % 2) { b++; f = 1; }
			else if (b == 1 && a % 2 == 0) { a++; f = 0; }
			else {
				if (f) { a++; b--; }
				else { a--; b++; }
			}
		}
		printf("TERM %d IS %d/%d\n", n, a, b);
	}
	return 0;
}