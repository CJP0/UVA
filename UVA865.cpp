#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main()
{
	int n;
	char in[9999], plain[9999], subs[9999];
	scanf("%d", &n);
	getchar();
	getchar();
	while (n--) {
		gets_s(plain);
		gets_s(subs);
		puts(subs);
		puts(plain);
		while (1) {
			gets_s(in);
			if (strlen(in) == 0)
				break;
			for (int i = 0; i < strlen(in); i++) {
				for (int j = 0; j < strlen(plain); j++) {
					if (in[i] == plain[j]) {
						in[i] = subs[j];
						break;
					}
				}
			}
			puts(in);
			for (int i = 0; i < strlen(in); i++)
				in[i] = '\0';
		}
		printf("\n");
	}
}