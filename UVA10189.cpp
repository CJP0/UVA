#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int n, m, count = 0;
	while (scanf("%d %d", &n, &m) != EOF && n) {
		while (getchar() != '\n');
		if (count) puts("");
		char list[110][110];
		for (int i = 0; i<n; i++)
			fgets(list[i], sizeof(list[i]), stdin);
		printf("Field #%d:\n", ++count);
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<m; j++) {
				if (list[i][j] == '*') printf("*");
				else {
					int out = 0;
					if (list[i + 1][j] == '*') out++;
					if (list[i + 1][j + 1] == '*') out++;
					if (list[i + 1][j - 1] == '*') out++;
					if (list[i - 1][j] == '*') out++;
					if (list[i - 1][j + 1] == '*') out++;
					if (list[i - 1][j - 1] == '*') out++;
					if (list[i][j - 1] == '*') out++;
					if (list[i][j + 1] == '*') out++;
					printf("%d", out);
				}
			}
			puts("");
		}
	}
}