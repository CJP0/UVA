#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define swap(x,y,z) ((z)=(x), (x)=(y), (y)=(z))
typedef struct element {
	int asc;
	int fre;
}element;
void sort(element in[], int len) {
	element temp;
	for (int i = 0; i<len - 1; i++) {
		for (int j = 0; j<len - 1 - i; j++) {
			if (in[j].fre>in[j + 1].fre)
				swap(in[j], in[j + 1], temp);
			if (in[j].fre == in[j + 1].fre && in[j].asc<in[j + 1].asc)
				swap(in[j], in[j + 1], temp);
		}
	}
}
int main()
{
	char str[1000];
	int temp, c = 0;
	element record[100];
	while (fgets(str, sizeof(str), stdin) != NULL) {
		if (c++ && strlen(str)>2) puts("");
		int index[200], f = 0;
		for (int i = 0; i<200; i++) index[i] = -1;
		for (int i = 0; i<strlen(str); i++) {
			temp = (int)str[i];
			if (isalnum(str[i]) || (temp >= 32 && temp <= 128)) {
				if (index[temp]<0) {
					record[f].asc = temp;
					record[f].fre = 1;
					index[temp] = f;
					f++;
				}
				else {
					temp = index[temp];
					record[temp].fre++;
				}
			}
		}
		sort(record, f);
		for (int i = 0; i<f; i++) {
			printf("%d %d\n", record[i].asc, record[i].fre);
		}
	}
}