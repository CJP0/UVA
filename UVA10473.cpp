#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
char conversion(int in) {
	switch (in) {
	case 10: return 'A';
	case 11: return 'B';
	case 12: return 'C';
	case 13: return 'D';
	case 14: return 'E';
	case 15: return 'F';
	default: return in + '0';
	}
}
int conversion(char in) {
	switch (in) {
	case 'A': return 10;
	case 'B': return 11;
	case 'C': return 12;
	case 'D': return 13;
	case 'E': return 14;
	case 'F': return 15;
	default: return in - '0';
	}
}
int main()
{
	char str[100];
	while (scanf("%s",str) != EOF) {
		if (str[0] == '-') break;
		long long sum = 0, temp;
		if (str[1] == 'x') {
			int f = strlen(str) - 1, p = 0;
			for (int i = f; i > 1; i--) {
				sum += (conversion(str[i]))*pow(16, p);
				p++;
			}
			printf("%lld\n", sum);
		}
		else {
			char buffer[100];
			int p = 0;
			sscanf(str, "%lld", &temp);
			while (temp) {
				buffer[p] = conversion((int)(temp % 16));
				p++;
				temp /= 16;
			}
			printf("0x");
			for (int i = p - 1; i >= 0; i--)
				printf("%c", buffer[i]);
			printf("\n");
		}
	}
}