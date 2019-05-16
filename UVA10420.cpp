#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define swap(x,y,z) ((z)=(x),(x)=(y),(y)=(z))
typedef struct list {
	char name[30];
	int count;
};
void sort(list in[],int size) {
	list temp;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (in[j].name[0] > in[j + 1].name[0]) swap(in[j], in[j + 1], temp);
		}
	}
}
int main()
{
	int n;
	char str[100];
	list record[1000];
	while (scanf("%d", &n) != EOF) {
		getchar();
		int c = 0;
		while (n--) {
			fgets(str, sizeof(str), stdin);
			for (int i = 0; i < strlen(str); i++) {
				if (str[i] == ' ') {
					str[i] = '\0';
					break;
				}
			}
			int  f = 1;
			for (int i = 0; i < c; i++) {
				if (strcmp(str, record[i].name) == 0) { record[i].count++; f = 0; break; }
			}
			if (f) {
				strcpy(record[c].name, str);
				record[c].count = 1;
				c++;
			}
		}
		sort(record, c);
		for (int i = 0; i < c; i++)
			printf("%s %d\n", record[i].name, record[i].count);
	}
}