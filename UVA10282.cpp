#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct dictionary {
	char index[20];
	char foreign[20];
};
int main()
{
	dictionary list[1000];
	char str[20], *ptr;
	int i;
	for (i = 0; i < 100000; i++) {
		fgets(str, sizeof(str), stdin);
		if (strlen(str) == 1) break;
		int f = 0;
		ptr = strtok(str, " ");
		while (ptr != NULL) {
			if (f) sscanf(ptr, "%s", list[i].foreign);
			else {
				sscanf(ptr, "%s", list[i].index);
				f = 1;
			}
			ptr = strtok(NULL, " ");
		}
	}
	int len = i;
	while (scanf("%s", str) != EOF) {
		int f = 1;
		for (i = 0; i <= len; i++) {
			if (strcmp(str, list[i].foreign) == 0) {
				f = 0;
				break;
			}
		}
		if (f) printf("eh\n");
		else printf("%s\n", list[i].index);
	}
}