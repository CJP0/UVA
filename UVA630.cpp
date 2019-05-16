#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define swap(x,y,z) ((z)=(x),(x)=(y),(y)=(z))
char *charsort(char in[]) {
	char temp, *arr;
	arr = (char *)malloc(sizeof(char) * 30);
	for (int i = 0; i < 30; i++)
		*(arr + i) = '\0';
	for (int i = 0; i < strlen(in); i++)
		arr[i] = in[i];
	for (int i = 0; i < strlen(in) - 1; i++) {
		for (int j = 1; j < strlen(in); j++) {
			if (arr[j - 1] > arr[j])
				swap(arr[j - 1], arr[j], temp);
		}
	}
	return arr;
}
int main()
{
	int casen, n;
	char e[5] = { "END" };
	scanf("%d", &casen);
	getchar();
	while (casen--) {
		char inc[1005][30], search[30];
		getchar();
		scanf("%d", &n);
		getchar();
		for (int i = 0; i < n; i++)
			gets_s(inc[i]);
		while (gets_s(search) != NULL && strcmp(e, search)) {
			int count = 1;
			printf("Anagrams for: %s\n", search);
			for (int i = 0; i < n; i++) {
				if (strcmp(charsort(search), charsort(inc[i])) == 0) {
					printf("  %d) %s\n", count, inc[i]);
					count++;
				}
			}
			if (count == 1)
				printf("No anagrams for: %s\n", search);
		}
		if (casen)
			printf("\n");
	}
}