#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int nsort(int array[], int size);
int main()
{
	int n,arr[60],s,p;
	while (scanf("%d", &n) != EOF) {
		while (n--) {
			scanf("%d", &s);
			for (int i = 0; i < s; i++)
				scanf("%d", &arr[i]);
			p = nsort(arr, s);
			printf("Optimal train swapping takes %d swaps.\n", p);
		}
	}
}
int nsort(int array[], int size)
{
	int i, j, temp,r=0;

	for (i = 0; i < size - 1; i++) {
		for (j = 1; j < size; j++) {
			if (array[j - 1] > array[j]) {
				temp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = temp;
				r++;
			}
		}
	}
	return r;
}




