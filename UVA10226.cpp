#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define swap(x,y,z) ((z)=(x), (x)=(y), (y)=(z))
typedef struct tree {
	char name[35];
	int count;
}tree;
tree list[10000];
int searchList(char in[], int n) {
	for (int i = 0; i<n; i++) {
		if (strcmp(list[i].name, in) == 0) return i;
	}
	return -1;
}
void sort(int n) {
	tree temp;
	int f;
	for (int i = 0; i<n - 1; i++) {
		for (int j = 0; j<n - 1 - i; j++) {
			f = 0;
			while (list[j].name[f] == list[j + 1].name[f]) f++;
			if (list[j].name[f]>list[j + 1].name[f])
				swap(list[j], list[j + 1], temp);
		}
	}
}
int main()
{
	char str[35];
	int counter, n, f, temp, len;
	scanf("%d", &n);
	while (getchar() != '\n');
	while (getchar() != '\n');
	while (n--) {
		counter = 0;
		f = 0;
		for (int i = 0; i<10000; i++) list[i].count = 0;
		while (fgets(str, sizeof(str), stdin) != NULL) {
			if (strlen(str)<2) break;
			len = strlen(str);
			if (str[len - 1] == '\n') str[len - 1] = '\0';
			//printf("=====%s\n",str);
			temp = searchList(str, f);
			if (temp >= 0) {
				list[temp].count += 1;
			}
			else {
				strcpy(list[f].name, str);
				list[f].count = 1;
				f++;
			}
			counter++;
		}
		sort(f);
		for (int i = 0; i<f; i++) {
			double buffer = ((double)(list[i].count * 100) / (double)counter);
			printf("%s %.4lf\n", list[i].name, buffer);
		}
		if (n) puts("");
	}
}