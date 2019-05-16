#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int n, s;
	double in[1100];
	char str[10];
	while (scanf("%d", &n) != EOF) {
		getchar();
		for (int i = 1; i <= n; i++) {
			fgets(str, sizeof(str), stdin);
			sscanf(str + 4, "%d", &s);
			int f = 0;
			for (int j = 0; j < s*s; j++) {
				scanf("%lf", &in[j]);
				if (in[j] < 0) f = 1;
			}
			while (getchar() != '\n');
			if (f) { printf("Test #%d: Non-symmetric.\n", i); continue; }
			else {
				for (int j = 0; j <= (s*s - 1 - j); j++) {
					if (in[j] != in[s*s - 1 - j]) { f = 1; break; }
				}
			}
			if(f) printf("Test #%d: Non-symmetric.\n", i);
			else printf("Test #%d: Symmetric.\n", i);
		}
	}
}