#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int gcd(long long a, long long b) {
	if (b) while ((a %= b) && (b %= a));
	return (int)(a + b);
}
long long convert(char in[]) {
	int len = strlen(in) - 1;
	if (in[len] == '\n') len--;
	long long out = 0;
	for (int i = len; i >= 0; i--) {
		if (in[i] == '1') {
			out += pow(2, (len - i));
		}
	}
	return out;
}
int main() {
	int n, c = 1;
	long long a, b;
	char str[40];
	scanf("%d", &n);
	while (getchar() != '\n');
	while (n--) {
		fgets(str, sizeof(str), stdin);
		a = convert(str);
		fgets(str, sizeof(str), stdin);
		b = convert(str);
		//printf("=======%lld==%lld\n",a,b);
		if (gcd(a, b)>1) printf("Pair #%d: All you need is love!\n", c++);
		else printf("Pair #%d: Love is not all you need!\n", c++);
	}
}