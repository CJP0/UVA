#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int n, inn[99999];
	char in[99999] = { 0 }, in2[99999] = { 0 }, *ptr;
	while (scanf("%d", &n) != EOF) {
		getchar();
		while (n--) {
			gets_s(in);
			gets_s(in2);
			int f = 0;
			ptr = strtok(in2, " ");
			while (ptr != NULL) {
				sscanf(ptr, "%d", &inn[f]);
				f++;
				ptr = strtok(NULL, " ");
			}
			int temp, buffer;
			for (int j = 1; j < f; j++) {
				temp = 0;
				for (int i = 0; i < strlen(in); i++) {
					buffer = in[i] - '0';
					temp = temp * 10 + buffer;
					temp %= inn[j];
				}
				if (temp)
					break;
			}
			if (temp)
				printf("%s - Simple.\n", in);
			else
				printf("%s - Wonderful.\n", in);
			for (int i = 0; in[i]; i++)
				in[i] = '\0';
			for (int i = 0; in2[i]; i++)
				in2[i] = '\0';
			for (int i = 0; inn[i]; i++)
				inn[i] = '\0';
		}
	}
}