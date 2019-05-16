#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
	int include[2000];
	int exist[2000];
	int remain;
	int elementn;
}team;
team in[2000];
team insert[2000];
int searchin(int s, int len) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < in[i].elementn; j++) {
			if (in[i].include[j] == s)
				return i;
		}
	}
}
int searchline(int s,int len) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < insert[i].elementn; j++)
			if (insert[i].include[j] == s)
				return i;
	}
	return -1;
}
int main()
{
	int n,t,number,count=1;
	char command[100],*ptr;
	while (scanf("%d", &n) != EOF) {
		getchar();
		if (n == 0)
			break;
		for (int i = 0; i < n; i++) {
			scanf("%d", &t);
			in[i].elementn = t;
			in[i].remain = 0;
			for (int j = 0; j < t; j++) {
				scanf("%d", &in[i].include[j]);
			}
		}
		int linef = 0,temp;
		getchar();
		printf("Scenario #%d\n", count);
		count++;
		while (gets_s(command) != NULL) {
			if (command[0] == 'S') {
				printf("\n");
				break;
			}
			else if (command[0] == 'E') {
				int a = 0;
				ptr = strtok(command," ");
				while (ptr != NULL) {
					a ? sscanf(ptr, "%d", &number) : a = 1;
					ptr = strtok(NULL, " ");
				}
				printf("# %d\n", number);
				temp = searchline(number, linef);
				if (linef && temp != -1) {
					insert[temp].exist[insert[temp].remain] = number;
					insert[temp].remain++;
				}
				else {
					temp = searchin(number, n);
					insert[linef] = in[temp];
					insert[linef].exist[insert[linef].remain] = number;
					insert[linef].remain++;
					linef++;
				}
			}
			else {
				printf("%d\n", insert[0].exist[0]);
				if (insert[0].remain == 1) {
					for (int i = 1; i < linef; i++) {
						insert[i - 1] = insert[i];
					}
					linef--;
				}
				else {
					for (int i = 1; i < insert[0].remain; i++) {
						insert[0].exist[i - 1] = insert[0].exist[i];
					}
					insert[0].remain--;
				}
			}
		}
	}
}