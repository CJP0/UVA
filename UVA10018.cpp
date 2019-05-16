#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int reverse(int a) {
	int out = 0;
	while (a) {
		out = (out * 10) + (a % 10);
		a /= 10;
	}
	return out;
}
int palindrome(int a) {
	int b = reverse(a);
	if (a == b)
		return 0;
	else
		return 1;
}
int main()
{
	int n,in;
	while (scanf("%d", &n) != EOF) {
		while (n--) {
			scanf("%d", &in);
			int count = 0;
			do{
				count++;
				in += reverse(in);
			}while (palindrome(in));
			printf("%d %d\n", count, in);
		}
	}
}