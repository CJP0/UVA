#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void print1(int array[], int t,int p, int position);
void print2(int array[], int t,int p, int position);
char *digital[10] = { "-|| ||-","  |  | ", "- |-| -","- |- |-"," ||- | ","-| - |-","-| -||-","- |  | ","-||-||-","-||- |-" };
int main()
{
	
	int s, n;
	while (scanf("%d %d", &s, &n) != EOF && s) {
		int nd[10] = { 0 },p=0;
		while (n) {
			nd[p] = n % 10;
			n /= 10;
			p++;
		}
		int po[5] = { 0,1,3,4,6 },x=1;
		for (int i = 0; i < 5; i++) {
			x ? print1(nd, s, p, po[i]):print2(nd, s, p, po[i]);
			x ? x = 0 : x = 1;
		}
		printf("\n");
	}
}
void print1(int array[], int t,int p,int position) {
	for (int i = p - 1; i >= 0; i--) {
		printf(" ");
		for (int j = 0; j < t; j++)
			printf("%c", *(digital[array[i]] + position));
		i == 0 ? printf(" \n") : printf("  ");
	}
}
void print2(int array[], int t, int p, int position) {
	for (int j = 0; j < t; j++) {
		for (int i = p - 1; i >= 0; i--) {
			printf("%c", *(digital[array[i]] + position));
			for (int z = 0; z < t; z++)
				printf(" ");
			printf("%c", *(digital[array[i]] + (position + 1)));
			i == 0 ? printf("\n") : printf(" ");
		}
	}
}