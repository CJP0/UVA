#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int convert(char in) {
	if (isdigit(in))
		return in - '0';
	else if (isupper(in))
		return in - 'A' + 10;
	else if (islower(in))
		return in - 'a' + 36;
}
int main()
{
	char in[100];
	while (scanf("%s", in) != EOF) {
		int sum = 0, max = 1, temp, f;
		for (int i = 0; i<strlen(in); i++) {
			if (isalnum(in[i])) {
				temp = convert(in[i]);
				sum += temp;
				if (temp>max) max = temp;
			}
		}
		for (f = max; (f<64) && (sum%f); f++);
		if (f>62) printf("such number is impossible!\n");
		else printf("%d\n", f + 1);
	}
}