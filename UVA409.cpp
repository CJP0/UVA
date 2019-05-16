#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char *strlwr(char *str)
{
	unsigned char *p = (unsigned char *)str;
	while (*p) {
		*p = tolower((unsigned char)*p);
		p++;
	}
	return str;
}
int main()
{
	int k, e, c = 1;
	while (scanf("%d %d", &k, &e) != EOF) {
		getchar();
		char keyword[30][100] = { 0 }, text[30][100] = { 0 }, *ptr, buffer[100];
		int count[30] = { 0 }, m = 0;
		for (int i = 0; i<30; i++)
			count[i] = 0;
		for (int i = 0; i < k; i++)
			gets_s(keyword[i]);
		for (int i = 0; i < e; i++) {
			gets_s(buffer);
			for (int p = 0; p < strlen(buffer); p++)
				text[i][p] = buffer[p];
			strlwr(buffer);
			ptr = strtok(buffer, " ");
			while (ptr != NULL) {
				for (int z = 0; z<strlen(ptr); z++)
					if (isalnum(ptr[z]) == 0)
						ptr[z] = '\0';
				for (int j = 0; j < k; j++) {
					if (strcmp(ptr, keyword[j]) == 0) {
						count[i]++;
						break;
					}
				}
				ptr = strtok(NULL, " ");
			}
			if (count[i] > m)
				m = count[i];
		}
		printf("Excuse Set #%d\n", c);
		c++;
		for (int i = 0; i < e; i++) {
			if (m == count[i])
				puts(text[i]);
		}
		printf("\n");
	}
}